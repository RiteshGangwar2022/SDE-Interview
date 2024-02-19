#include <bits/stdc++.h>
using namespace std;


//memoization=> TC=>O(n) , SC=>O(n)+O(n)=>recursive stack space
/*int helper(int n, vector<int> &dp)
{

    if (n <= 1)
    {

        return n;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    return dp[n] = helper(n - 1, dp) + helper(n - 2, dp);
}*/

int main()
{

    int n;
    cin >> n; // to get nth fibo

    vector<int> dp(n + 1, -1);
    //int ans = helper(n, dp);

    //iterative app=>tabulation=> to reduce the space complexity

  /*  dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){

        dp[i]=dp[i-1]+dp[i-2];
    }
    int ans=dp[n];*/

    //as above we are doing some only previous two elements, so no need to maintain the whole array
    //just take two variables

    int prev_2=0;
    int prev_1=1;
     
    for(int i=2;i<=n;i++){
       
       int ans=prev_2+prev_1;
       prev_2=prev_1;
       prev_1=ans;  
    }
    int ans=prev_1;
    cout << "nth fibonacci " << ans << endl;

    return 0;
}