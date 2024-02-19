#include <bits/stdc++.h>
using namespace std;

// Time complexity=> O(n) and space complexity=> O(n*2*3)+O(N)
/*int helper_maxprofit(int index, int buy, int transaction, vector<int> &prices, vector<vector<vector<int>>> &dp)
{

    if (index == prices.size() || transaction == 0)
    {
        return 0;
    }

    if (dp[index][buy][transaction] != -1)
    {
        return dp[index][buy][transaction];
    }
    int profit = 0;

    if (buy)
    {

        int take = -prices[index] + helper_maxprofit(index + 1, 0, transaction, prices, dp);
        int not_take = helper_maxprofit(index + 1, 1, transaction, prices, dp);
        profit = max(take, not_take);
    }
    else
    {

        int sell = prices[index] + helper_maxprofit(index + 1, 1, transaction - 1, prices, dp);
        int not_sell = helper_maxprofit(index + 1, 0, transaction, prices, dp);
        profit = max(sell, not_sell);
    }

    return dp[index][buy][transaction] = profit;
}*/

int maxprofit(vector<int> &prices, int k)
{
    // maximum transation allowed is 2
    // as there are 3 changing parameters, so we required dp[n+1][2][3]
    // bcz, transaction can hold values of  0,1,2

    /*int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, -1)));
    int transaction = k;
    return helper_maxprofit(0, 1, transaction, prices, dp);*/

    // tabulation=>optimizing space

    /*  int n = prices.size();
       vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

       // base case=> if index==n, whatever the value of transation and buy, dp[n][buy][transation]=0
       // trasation==0, whatever the value of buy or index,dp[index][buy][0]=0
       // but,as we have already intialized, our dp with 0, so no need to write seperate base cases

       // reverse every operation

       for (int index = n - 1; index >= 0; index--)
       {

           for (int buy = 0; buy <= 1; buy++)
           {

               for (int transaction = 1; transaction <= k; transaction++)
               {
                   int profit = 0;

                   if (buy == 0)
                   {

                       int take = -prices[index] + dp[index + 1][1][transaction];
                       int not_take = dp[index + 1][0][transaction];
                       profit = max(take, not_take);
                   }
                   else
                   {

                       int sell = prices[index] + dp[index + 1][0][transaction - 1];
                       int not_sell = dp[index + 1][1][transaction];
                       profit = max(sell, not_sell);
                   }

                   dp[index][buy][transaction] = profit;
               }
           }

       }

        return dp[0][0][k];*/

    // further space optimization
    // we just required space of 2*3=constant
    int n = prices.size();

    vector<vector<int>> next(2, vector<int>(k + 1, 0));
    vector<vector<int>> curr(2, vector<int>(k + 1, 0));

    for (int index = n - 1; index >= 0; index--)
    {

        for (int buy = 0; buy <= 1; buy++)
        {

            for (int transaction = 1; transaction <= k; transaction++)
            {
                int profit = 0;

                if (buy == 0)
                {

                    int take = -prices[index] + next[1][transaction];
                    int not_take = next[0][transaction];
                    profit = max(take, not_take);
                }
                else
                {

                    int sell = prices[index] + next[0][transaction - 1];
                    int not_sell = next[1][transaction];
                    profit = max(sell, not_sell);
                }

                curr[buy][transaction] = profit;
            }
        }
        next = curr;
    }

    return curr[0][k];
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> prices;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        prices.push_back(x);
    }

    int max_profit = maxprofit(prices, k);
    cout << max_profit << endl;
    return 0;
}