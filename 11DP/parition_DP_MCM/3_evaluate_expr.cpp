#include <bits/stdc++.h>
using namespace std;


//this code and approach is correct it might not passing all the test cases, bcz interger overlfow, or we should apply mod to every operation
long long int mod=1000000007;

int evaluateExp_helper(int i, int j, string exp, bool istrue, vector<vector<vector<long long int>>> &dp)
{

    // base case

    if (i > j)
    {
        return false;
    }
    if (i == j)
    {

        if (istrue)
        {
            return exp[i] == 'T'; // to get the number of ways to evaluate true
        }
        else
        {
            return exp[i] == 'F'; // to get the number of ways to evaluate false
        }
    }

    if (dp[i][j][istrue] != -1)
    {
        return dp[i][j][istrue];
    }

    int res = 0;

    for (int k = i + 1; k < j; k += 2)
    {

        int left_true = evaluateExp_helper(i, k - 1, exp, 1, dp);
        int left_false = evaluateExp_helper(i, k - 1, exp, 0, dp);

        int right_true = evaluateExp_helper(k + 1, j, exp, 1, dp);
        int right_false = evaluateExp_helper(k + 1, j, exp, 0, dp);

        // different ways to evaluate to expression according to the operator

        if (exp[k] == '&')
        {

            if (istrue)
            {

                res += (left_true * right_true)%mod;
            }
            else
            {
                res += (left_true * right_false + right_true * left_false + left_false * right_false)%mod;
            }
        }

        if (exp[k] == '^')
        {

            if (istrue)
            {

                res += (left_true * right_false + left_false * right_true)%mod;
            }
            else
            {
                res += (left_true * right_true + left_false * right_false)%mod;
            }
        }

        if (exp[k] == '|')
        {

            if (istrue)
            {
                res += (left_true * right_true + left_true * right_false + right_true * left_false)%mod;
            }
            else
            {
                res += (left_false * right_false)%mod;
            }
        }
    }

    return dp[i][j][istrue] = res%mod;
}

int evaluateExp(string exp)
{

    int i = 0;
    int j = exp.size() - 1;
    bool istrue = true;
    int n = exp.size();
    vector<vector<vector<long long int>>> dp(n, vector<vector<long long int>>(n, vector<long long int>(2, -1)));
    int res = evaluateExp_helper(i, j, exp, istrue, dp);
    return res;
}

int main()
{

    string exp;
    cin >> exp;

    int res = evaluateExp(exp);
    cout << "total number of ways " << res << endl;

    return 0;
}