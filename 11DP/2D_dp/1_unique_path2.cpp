#include <bits/stdc++.h>
using namespace std;

/*int find_ways_helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{

    if (i < 0 || j < 0 || grid[i][j] == 1)
    {
        return 0;
    }

    if (i == 0 && j == 0)
    {
        return 1;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = find_ways_helper(i - 1, j, grid, dp);
    int left = find_ways_helper(i, j - 1, grid, dp);

    return dp[i][j] = left + up;
}*/

int find_ways(vector<vector<int>> &grid)
{

    int n = grid.size();
    int m = grid[0].size();
    /*vector<vector<int>> dp(n, vector<int>(m, -1));
    int res = find_ways_helper(n - 1, m - 1, grid,dp);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return res;*/

    /*  vector<vector<int>> dp(n, vector<int>(m, 0));

      for (int i = 0; i < n; i++)
      {

          for (int j = 0; j < m; j++)
          {

              if (grid[i][j] == 1)
              {
                 dp[i][j]=0;
                  continue;
              }
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

              int left = 0;

              if (j > 0)
              {
                  left = dp[i][j - 1];
              }

              dp[i][j] = left + up;
          }
      }

      for (int i = 0; i < n; i++)
      {

          for (int j = 0; j < m; j++)
          {
              cout << dp[i][j] << " ";
          }
          cout << endl;
      }

      cout << dp[n - 1][m - 1] << endl;
      return dp[n - 1][m - 1];*/

    vector<int> prev(m, 0), curr(m, 0);

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            if (grid[i][j] == 1)
            {   
                curr[j]=0;
                continue;
            }
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

            int left = 0;

            if (j > 0)
            {
                left = curr[j - 1];
            }

            curr[j] = left + up;
        }
        prev = curr;
    }
    for (int i = 0; i < m; i++)
    {
        cout << prev[i] << " ";
    }
    cout << endl;

    cout << prev[m - 1] << endl;
    return prev[m - 1];
}
int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid;

    for (int i = 0; i < n; i++)
    {

        vector<int> temp;

        for (int j = 0; j < m; j++)
        {

            int x;
            cin >> x;
            temp.push_back(x);
        }
        grid.push_back(temp);
    }
    int ways = find_ways(grid);
    cout << "Total unique ways " << ways << endl;
    return 0;
}