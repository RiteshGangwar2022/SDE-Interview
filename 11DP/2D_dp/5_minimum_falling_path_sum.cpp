#include <bits/stdc++.h>
using namespace std;

/*int min_path_sum_helper(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0 || j >= grid.size())
    {
        return INT_MAX;
    }

    if (i == 0)
    {
        return grid[i][j];
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int left_dia = min_path_sum_helper(i - 1, j - 1, grid, dp);
    int right_dia = min_path_sum_helper(i - 1, j + 1, grid, dp);
    int up = min_path_sum_helper(i - 1, j, grid, dp);

    int temp = grid[i][j] + min(up, min(left_dia, right_dia));
    return dp[i][j] = temp;
}*/
int min_path_sum(vector<vector<int>> &grid)
{
    int n = grid.size();
    /*int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int res = INT_MAX;

    for (int j = n - 1; j >= 0; j--)
    {
        int temp = min_path_sum_helper(n - 1, j, grid, dp);
        res = min(res, temp);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return res;*/

    /* vector<vector<int>> dp(n, vector<int>(n, 0));

     for (int i = 0; i < n; i++)
     {
         dp[0][i] = grid[0][i];
     }

     for (int i = 1; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             int down = dp[i - 1][j];

             int leftdia = INT_MAX;
             if (j - 1 >= 0)
             {
                 leftdia = dp[i - 1][j - 1];
             }
             int rightdia = INT_MAX;

             if (j + 1 < n)
             {
                 rightdia = dp[i - 1][j + 1];
             }
             dp[i][j] = grid[i][j] + min(down, min(leftdia, rightdia));
         }
     }

     for (int i = 0; i < n; i++)
     {
         for (int j = 0; j < n; j++)
         {
             cout << dp[i][j] << " ";
         }
         cout << endl;
     }

     // getting min from last row
     int res = INT_MAX;

     for (int i = 0; i < n; i++)
     {

         res = min(res, dp[n - 1][i]);
     }

     return res;*/

    vector<int> prev(n, INT_MAX), curr(n, INT_MAX);

    for (int i = 0; i < n; i++)
    {
        prev[i] = grid[0][i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int down = prev[j];

            int leftdia = INT_MAX;
            if (j - 1 >= 0)
            {
                leftdia = prev[j - 1];
            }
            int rightdia = INT_MAX;

            if (j + 1 < n)
            {
                rightdia = prev[j + 1];
            }
            curr[j] = grid[i][j] + min(down, min(leftdia, rightdia));
        }
        prev = curr;
    }

    for (int j = 0; j < n; j++)
    {
        cout << prev[j] << " ";
    }
    cout << endl;

    // getting min from last row
    int res = INT_MAX;

    for (int i = 0; i < n; i++)
    {

        res = min(res, prev[i]);
    }

    return res;
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