#include <bits/stdc++.h>
using namespace std;

// memoization=> TC=>O(n) and SC=>O(n*w)+O(N)->recursive stack space
/*int knapsack_helper(vector<int> &weight, vector<int> &value, int n, int maxWeight, vector<vector<int>> &dp)
{

    // base case

    if (maxWeight == 0)
    {
        return 0;
    }
    if (n == 0)
    {

        return (maxWeight / weight[0]) * value[0]; // bcz we can take same element multiple times, of same weight if it is in weight range
    }

    if (dp[n][maxWeight] != -1)
    {
        return dp[n][maxWeight];
    }

    // not pick

    int not_pick = knapsack_helper(weight, value, n - 1, maxWeight, dp);

    // pick
    int pick = INT_MIN;
    if (weight[n] <= maxWeight)
    {
        // only difference between 0/1 and unbounded knapsack is that, we will not move to previous index on taking the profit
        pick = value[n] + knapsack_helper(weight, value, n, maxWeight - weight[n], dp);
    }

    return dp[n][maxWeight] = max(pick, not_pick);
}*/
int knapsack(vector<int> &weight, vector<int> &value, int n, int maxWeight)
{

    /*vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    int res = knapsack_helper(weight, value, n-1, maxWeight, dp);

    for (int i = 0; i <n; i++)
    {

        for (int j = 0; j <= maxWeight; j++)
        {

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return res;*/

    /*  // tabulation=>space optimization=> O(n*w)
      vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));

      // base case
      // if weight is 0, then res will be independent on n, so all will be 0
      // if n==0, then , it will be independent on weight
      // so, first row and first column will be 0, but dp already intialzed with 0


       //base case to pick first element of each column
       for(int i=weight[0];i<=maxWeight;i++){
          dp[0][i]=(i/weight[0])*value[0];
       }


      for (int i = 1; i <n; i++)
      {

          for (int j = 0; j <= maxWeight; j++)
          {
              int not_pick = dp[i - 1][j];

              // pick
              int pick = 0;
              if (weight[i] <= j)
              {
                  //just don't move to previous iteration=>dp[i-1]->dp[i]
                  pick = value[i] + dp[i][j - weight[i]];
              }
              dp[i][j] = max(pick, not_pick);
          }
      }


      for (int i = 0; i < n; i++)
      {
          for (int j = 0; j <= maxWeight; j++)
          {
              cout << dp[i][j] << " ";
          }
          cout << endl;
      }
      return dp[n-1][maxWeight];*/

    // space optimization=>O(1)

    vector<int> prev(maxWeight + 1, 0);
    vector<int> curr(maxWeight + 1, 0);

    // base case
    // if weight is 0, then res will be independent on n, so all will be 0
    // if n==0, then , it will be independent on weight
    // so, first row and first column will be 0, but dp already intialzed with 0

    // base case to pick first element of each column
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = (i / weight[0]) * value[0];
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= maxWeight; j++)
        {
            int not_pick = prev[j];

            // pick
            int pick = 0;
            if (weight[i] <= j)
            {
                // just don't move to previous iteration=>dp[i-1]->dp[i]
                pick = value[i] + curr[j - weight[i]];
            }
            curr[j] = max(pick, not_pick);
        }
        prev = curr;
    }

    for (int j = 0; j <= maxWeight; j++)
    {
        cout << prev[j] << " ";
    }
    cout << endl;

    return prev[maxWeight];
}
int main()
{

    int n;
    cin >> n;
    int maxWeight;
    cin >> maxWeight;
    vector<int> value;

    vector<int> weight;

    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        value.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        weight.push_back(x);
    }

    int max_profit = knapsack(weight, value, n, maxWeight);

    cout << "Max Profit " << max_profit << endl;

    return 0;
}