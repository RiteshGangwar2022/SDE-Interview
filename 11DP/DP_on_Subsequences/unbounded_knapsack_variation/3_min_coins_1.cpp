#include <bits/stdc++.h>
using namespace std;

/*int coinChange_helper(vector<int> &coins, int target, int n, vector<vector<int>> &dp)
{

    if (n == 0)
    {
        // we will have two cases here, either target is divisible by coins[0] or not

        if ((target % coins[0]) == 0)
        {
            return target / coins[0];
        }
        else
        {
            return 1e9;//return this instead of INT_MAX, otherewise it will result in interger overflow
        }
    }

    if(dp[n][target]!=-1){

        return dp[n][target];
    }

    int not_take = 0 + coinChange_helper(coins, target, n - 1, dp);

    int take = INT_MAX;

    if (coins[n] <= target)
    {
        take = 1 + coinChange_helper(coins, target - coins[n], n, dp);
    }
    return dp[n][target]=min(take, not_take);
}*/

int coinChange(vector<int> &coins, int target, int n)
{

    /* vector<vector<int>> dp(n, vector<int>(target + 1, -1));
     int res = coinChange_helper(coins, target, n - 1, dp);

     if (res == INT_MAX)
     {
         return -1;
     }
     return res;*/

  /*  vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // base case
    for (int i = 0; i <= target; i++)
    {

        if ((i % coins[0]) == 0)
        {
            dp[0][i] = i / coins[0];
        }
        else
        {
            dp[0][i] = 1e9;
        }
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= target; j++)
        {

            int not_take = dp[i - 1][j];
            int take = 1e9;

            if (coins[i] <= j)
            {
                take = 1 + dp[i][j - coins[i]];
            }
            dp[i][j] = min(take, not_take);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= target; j++)
        {

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    int res=dp[n - 1][target];
    if(res==1e9){
        return -1;
    }
    return res;*/

     vector<int>prev(target+1,0);
     vector<int>curr(target+1,0);

    // base case
    for (int i = 0; i <= target; i++)
    {

        if ((i % coins[0]) == 0)
        {
            prev[i] = i / coins[0];
        }
        else
        {
            prev[i] = 1e9;
        }
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= target; j++)
        {

            int not_take = prev[j];
            int take = 1e9;

            if (coins[i] <= j)
            {
                take = 1 + curr[j - coins[i]];
            }
            curr[j] = min(take, not_take);
        }
        prev=curr;
    }


        for (int j = 0; j <= target; j++)
        {

            cout << prev[j] << " ";
        }
        cout << endl;
  

    int res=prev[target];
    if(res==1e9){
        return -1;
    }
    return res;
}

int main()
{

    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> coins;

    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        coins.push_back(x);
    }

    int res = coinChange(coins, target, n);
    cout << "minimum coins " << res << endl;

    return 0;
}