#include <bits/stdc++.h>
using namespace std;

bool check(string str, int i, int j)
{

    while (i <= j)
    {

        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

/*int helper(int i, int j, string str, vector<vector<int>> &dp)
{

    if (i > j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if (check(str, i, j))
    {
        return 0;
    }

    int res = INT_MAX;

    for (int k = i; k < j; k++)
    {
        int tempans = helper(i, k, str, dp) + helper(k + 1, j, str, dp) + 1; // 1 means we are adding one partition in our res
        res = min(res, tempans);
    }
    return dp[i][j] = res;
}*/

int minCut(string str)
{

    /*int i = 0;
    int j = str.size() - 1;
    int n = str.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int res = helper(i, j, str, dp);

    return res;*/

    int n = str.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    int res = INT_MAX;

    for (int i = n - 1; i >= 0; i--)
    {

        for (int j = i + 1; j < n; j++)
        {
            if (check(str, i, j))
            {
                dp[i][j] = 0;
                continue;
            }
            int res = INT_MAX;

            for (int k = i; k < j; k++)
            {
                int tempans = dp[i][k] + dp[k + 1][j] + 1; // 1 means we are adding one partition in our res
                res = min(res, tempans);
            }
            dp[i][j] = res;
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[0][n - 1];
}

int main()
{

    string str;
    cin >> str;

    // this is just the variation of matrix chain multiplication, just add 1 to recusive, means, 1 partition on dividing the string
    int res = minCut(str);
    cout << "minimum cut pallindrome " << res << endl;
    return 0;
}