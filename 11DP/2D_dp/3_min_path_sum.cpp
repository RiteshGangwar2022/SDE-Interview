#include <bits/stdc++.h>
using namespace std;

/*int min_path_sum_helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }

    if (i == 0 && j == 0)
    {
        return grid[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int up = min_path_sum_helper(i - 1, j, grid, dp);
    int left = min_path_sum_helper(i, j - 1, grid, dp);

    int temp = grid[i][j] + min(left, up);
    return dp[i][j] = temp;
}*/
int min_path_sum(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    /*vector<vector<int>> dp(n, vector<int>(m, -1));
    int res = min_path_sum_helper(n - 1, m - 1, grid, dp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return res;*/

    /*vector<vector<int>> dp(n, vector<int>(m, INT_MAX));

     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < m; j++)
         {
             if (i == 0 && j == 0)
             {
                 dp[i][j] = grid[i][j];
                 continue;
             }

             int up = INT_MAX;

             if (i > 0)
             {
                 up = dp[i - 1][j];
             }

             int left = INT_MAX;
             if (j > 0)
             {
                 left = dp[i][j - 1];
             }

             dp[i][j] = grid[i][j] + min(left, up);
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

     return dp[n-1][m-1];*/

    vector<int> prev(m, INT_MAX), curr(m, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 && j == 0)
            {
                curr[j] = grid[i][j];
                continue;
            }

            int up = INT_MAX;

            if (i > 0)
            {
                up = prev[j];
            }

            int left = INT_MAX;
            if (j > 0)
            {
                left = curr[j - 1];
            }

            curr[j] = grid[i][j] + min(left, up);
        }
        prev=curr;
    }

    for (int j = 0; j < m; j++)
    {
        cout << prev[j] << " ";
    }
    cout << endl;

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
    int min_sum = min_path_sum(grid);
    cout << "min cost " << min_sum << endl;
    return 0;
}