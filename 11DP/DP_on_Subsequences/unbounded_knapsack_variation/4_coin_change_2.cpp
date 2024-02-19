#include <bits/stdc++.h>
using namespace std;

/*int change_helper(vector<int> &coins, int n, int target, vector<vector<int>> &dp)
{

    if (n == 0)
    {

        if ((target % coins[0]) == 0)
        {
            return 1;
        }
        else
        {

            return 0;
        }
    }

    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    int not_pick = change_helper(coins, n - 1, target, dp);

    int pick = 0;

    if (coins[n] <= target)
    {
        pick =change_helper(coins, n, target - coins[n], dp);
    }

    return dp[n][target] = (pick+not_pick);
}*/
int change(vector<int> &coins, int target)
{
    int n = coins.size();
    /* vector<vector<int>> dp(n, vector<int>(target + 1, -1));
     int res = change_helper(coins, n - 1, target, dp);

     for (int i = 0; i < n; i++)
     {

         for (int j = 0; j <= target; j++)
         {

             cout << dp[i][j] << " ";
         }
         cout << endl;
     }

     return res;*/

    /* vector<vector<int>> dp(n, vector<int>(target + 1, 0));

     // base case
     for (int i = 0; i <= target; i++)
     {

         if ((i % coins[0]) == 0)
         {
             dp[0][i] = 1;
         }
     }

     for (int i = 1; i < n; i++)
     {

         for (int j = 0; j <= target; j++)
         {

             int not_pick = dp[i - 1][j];

             int pick = 0;

             if (coins[i] <= j)
             {
                 pick = dp[i][j - coins[i]];
             }

              dp[i][j] = (pick + not_pick);
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

     return dp[n-1][target];*/

    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    // base case
    for (int i = 0; i <= target; i++)
    {

        if ((i % coins[0]) == 0)
        {
            prev[i] = 1;
        }
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= target; j++)
        {

            int not_pick = prev[j];

            int pick = 0;

            if (coins[i] <= j)
            {
                pick = curr[j - coins[i]];
            }

            curr[j] = (pick + not_pick);
        }
        prev = curr;
    }

    for (int j = 0; j <= target; j++)
    {

        cout << prev[j] << " ";
    }
    cout << endl;

    return prev[target];
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

    int res = change(coins, target);
    cout << "maximum coins " << res << endl;
    return 0;
}