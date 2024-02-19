#include <bits/stdc++.h>
using namespace std;

int find_square(vector<vector<int>> &grid)
{  

    //we can also write memoized code for this, see vs code soln

    int n = grid.size();
    int m = grid[0].size();

    // we can directly solve this question using iterative dp
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // intialize first row and first coloumn of DP with grid

    for (int i = 0; i < m; i++)
    {

        dp[0][i] = grid[0][i];
    }

    for (int i = 0; i < n; i++)
    {

        dp[i][0] = grid[i][0];
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {

            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j < m; j++)
        {

            if (grid[i][j] != 0)
            {

                int diagonal = dp[i - 1][j - 1];
                int up = dp[i - 1][j];
                int left = dp[i][j - 1];

                dp[i][j] = grid[i][j] + min(diagonal, min(up, left));
            }
        }
    }

    int total_square = 0;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            total_square += dp[i][j];
        }
    }

    return total_square;
}
int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid;

    for (int i = 0; i < n; i++)
    {

        vector<int> row;

        for (int j = 0; j < m; j++)
        {

            int x;
            cin >> x;
            row.push_back(x);
        }
        grid.push_back(row);
    }

    int number_of_square = find_square(grid);
    cout << "Total number of square " << number_of_square << endl;
    return 0;
}