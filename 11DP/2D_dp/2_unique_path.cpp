#include <bits/stdc++.h>
using namespace std;

/*int find_ways_helper(int i, int j, int n, int m, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0)
    {
        return 0;
    }

    // if we reach at (0,0)
    if (i == 0 && j == 0)
    {
        return 1;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = find_ways_helper(i - 1, j, n, m, dp);
    int left = find_ways_helper(i, j - 1, n, m, dp);

    return dp[i][j] = up + left;
}
*/
int find_ways(int n, int m)
{

    /* vector<vector<int>> dp(n, vector<int>(m,-1));
     int res = find_ways_helper(n - 1, m - 1, n, m, dp);

     for(int i=0;i<n;i++){

         for(int j=0;j<m;j++){
             cout<<dp[i][j]<<" ";
         }
         cout<<endl;
     }
     return res;*/

    /* vector<vector<int>> dp(n, vector<int>(m, 0));

     for (int i = 0; i < n; i++)
     {

         for (int j = 0; j < m; j++)
         {

             if (i == 0 && j == 0)
             {
                 dp[i][j] = 1;
                 continue;
             }

             int up = 0;
             if (i > 0)
             {
                 up = dp[i - 1][j];
             }
             int down = 0;
             if (j > 0)
             {
                 down = dp[i][j - 1];
             }
             dp[i][j] = up + down;
         }
     }

     for(int i=0;i<n;i++){

          for(int j=0;j<m;j++){
              cout<<dp[i][j]<<" ";
          }
          cout<<endl;
      }

     cout<<dp[n-1][m-1]<<endl;
     return dp[n-1][m-1];*/

    vector<int> prev(m, 0), curr(m, 0);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (i == 0 && j == 0)
            {
                curr[j] = 1;
                continue;
            }

            int up = 0;
            if (i > 0)
            {
                up = prev[j];
            }
            int down = 0;
            if (j > 0)
            {
                down = curr[j - 1];
            }
            curr[j] = up + down;
        }
        prev=curr;
    }

    for(int i=0;i<m;i++){

        cout<<prev[i]<<" ";
    }
    cout<<endl;

    cout<<prev[m-1]<<endl;
   return prev[m-1];
}
int main()
{

    int n, m;
    cin >> n >> m;

    int ways = find_ways(n, m);
    cout << "Total Number of ways " << ways << endl;
    return 0;
}