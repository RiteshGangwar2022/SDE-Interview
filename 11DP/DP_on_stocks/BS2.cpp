#include <bits/stdc++.h>
using namespace std;

/*int maxprofit_helper(vector<int>&prices,int index,int buy,vector<vector<int>>&dp){


      //base condition
      if(index==prices.size()){
          return 0;
      }

      if(dp[index][buy]!=-1){
          return dp[index][buy];
      }

      int profit=0;
      //if we are allowed to buy
      if(buy){

           //if we buy
           int take=-prices[index]+maxprofit_helper(prices,index+1,0,dp);//we cannot buy next stock again until we sell it

           //if we do not buy now
           int not_take=maxprofit_helper(prices,index+1,1,dp);//we can still buy next stock
           profit=max(take,not_take);
      }
      else{//if we have bought, now, we are allowed to sell

            int sell=prices[index]+maxprofit_helper(prices,index+1,1,dp);//as we have sell, so we can buy next stock
            int not_sell=maxprofit_helper(prices,index+1,0,dp);//as we have not sell, so, we can not buy next stock
            profit=max(sell,not_sell);
      }
      return dp[index][buy]=profit;
 }*/

int maxProfit(vector<int> &prices)
{

    /*int buy=1;
    int index=0;
    //memoization =>reduce time complexity from exponential to=> O(n*2) and, SC=>O(n*2)+O(n)
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2,-1));//n*2
    return maxprofit_helper(prices,index,buy,dp);*/

    // tabulation=>to optimize the space from O(N*2)+O(N)=> O(n*2)

    /* int n = prices.size();

     vector<vector<int>> dp(n + 1, vector<int>(2, 0));

     // base case will be dp[n][0]=dp[n][1]=0, bcz, if we are at last index, it will be 0 independent on buy or sell
     // as we have intialized our vector with 0, so, need to mention it seperately

     // just reverse the iterations


     for (int index = n - 1; index >= 0; index--)
     {

         for (int buy = 0; buy <= 1; buy++)
         {
              int profit=0;
             // if we are allowed to buy
             if (buy==0)
             {

                 // if we buy
                 int take = -prices[index] + dp[index + 1][1]; // we cannot buy next stock again until we sell it

                 // if we do not buy now
                 int not_take = dp[index + 1][0]; // we can still buy next stock
                 profit = max(take, not_take);
             }
             else
             { // if we have bought, now, we are allowed to sell

                 int sell = prices[index] + dp[index + 1][0]; // as we have sell, so we can buy next stock
                 int not_sell = dp[index + 1][1];             // as we have not sell, so, we can not buy next stock
                 profit = max(sell, not_sell);
             }
             dp[index][buy] = profit;
         }
     }


     for(int i=0;i<dp.size();i++){

         for(int j=0;j<2;j++){
             cout<<dp[i][j]<<" ";
         }
         cout<<endl;
     }

     return dp[0][0];*/

    // space optimization
    int n = prices.size();
    vector<int> next(2, 0), curr(2, 0);

    for (int index = n - 1; index >= 0; index--)
    {

        for (int buy = 0; buy <= 1; buy++)
        {
            int profit = 0;
            // if we are allowed to buy
            if (buy == 0)
            {

                // if we buy
                int take = -prices[index] + next[1]; // we cannot buy next stock again until we sell it

                // if we do not buy now
                int not_take = next[0]; // we can still buy next stock
                profit = max(take, not_take);
            }
            else
            { // if we have bought, now, we are allowed to sell

                int sell = prices[index] + next[0]; // as we have sell, so we can buy next stock
                int not_sell = next[1];             // as we have not sell, so, we can not buy next stock
                profit = max(sell, not_sell);
            }
            curr[buy] = profit;
        }
        next = curr;
    }

    for (int i = 0; i < curr.size(); i++)
    {
        cout << curr[i] << " ";
    }
    cout<<endl;

    return curr[0];
}
int main()
{

    int n;
    cin >> n;
    vector<int> prices;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        prices.push_back(x);
    }

    int max_profit = maxProfit(prices);
    cout << "maximum possible porfit " << max_profit << endl;
    return 0;
}