#include <bits/stdc++.h>
using namespace std;

/*int helper(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
{

    // base case
    // if there is single or no element in arr
    if (i == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int res = INT_MAX;
    // to divide partition between i and j, for all values of k
    for (int k = i; k <j; k++)
    {

        int tempans = helper(i, k, arr, dp) + helper(k + 1, j, arr, dp) + arr[i - 1] * arr[k] * arr[j]; // forumular as explained in copy
        res = min(res, tempans);
    }

    return dp[i][j] = res;
}
*/
int matrixChainMultiplication(vector<int> &arr, int n)
{
    /*vector<vector<int>> dp(n, vector<int>(n, -1));
    int res = helper(1, n - 1, arr, dp);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return res;*/

    vector<vector<int>> dp(n, vector<int>(n, 0));

    // base case if i==j so, dp[i][j]=0

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }
    //, but dp already intialized with 0

    for (int i = n - 1; i >= 1; i--)
    {

        for (int j = i + 1; j <= n - 1; j++)
        {

            int res = INT_MAX;
            // to divide partition between i and j, for all values of k
            for (int k = i; k < j; k++)
            {

                int tempans = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]; // forumular as explained in copy
                res = min(res, tempans);
            }
            dp[i][j] = res;
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
    return dp[1][n - 1];
}

int main()
{

    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        arr.push_back(x);
    }

    int res = matrixChainMultiplication(arr, n);
    cout << "minimum cost " << res << endl;
    return 0;
}