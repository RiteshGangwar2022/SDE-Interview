#include <bits/stdc++.h>
using namespace std;

int helper(int e, int f, vector<vector<int>> &dp)
{

    // base case
    if (e == 1 || f <= 1)
    {
        return f;
    }

    if (dp[e][f] != -1)
    {
        return dp[e][f];
    }
    int res = INT_MAX;

    // partition for all the floors
    for (int k = 1; k <= f; k++)
    {

        int break_egg = helper(e - 1, k - 1, dp);
        int not_break_egg = helper(e, f - k, dp);
        int tempans = 1 + max(break_egg, not_break_egg);

        res = min(res, tempans);
    }
    return dp[e][f] = res;
}
int eggDrop(int e, int f)
{

    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    int res = helper(e, f, dp);

    for (int i = 0; i <= e; i++)
    {

        for (int j = 0; j <= f; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return res;
}

int main()
{

    int e, f;
    cin >> e >> f;

    int res = eggDrop(e, f);
    cout << "minimum steps " << res << endl;
    return 0;
}