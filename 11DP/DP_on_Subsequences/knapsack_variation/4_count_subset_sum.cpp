#include <bits/stdc++.h>
using namespace std;

/*int subsetSumToK_helper(vector<int> &arr, int n, int target, vector<vector<int>> &dp)
{

    if (target == 0)
    {
        return 1;
    }

    if (n == 0)
    {

        if (arr[0] == target)
        {
            return 1;
        }
        return 0;
    }

    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    int not_pick = subsetSumToK_helper(arr, n - 1, target, dp);

    int pick = 0;

    if (arr[n] <= target)
    {
        pick = subsetSumToK_helper(arr, n - 1, target - arr[n], dp);
    }
    return dp[n][target] = not_pick + pick;
}*/

int findWays(vector<int> &arr, int k)
{
    /* int n = arr.size();
     int target = k;
     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
     int  res = subsetSumToK_helper(arr, n - 1, target, dp);

     for (int i = 0; i < n; i++)
     {

         for (int j = 0; j <= target; j++)
         {
             cout << dp[i][j] << " ";
         }
         cout << endl;
     }
     return res;*/

    /*int n=arr.size();

    int target = k;
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // base case=> if target==0, first colm, will be true

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    // base case=> if n==0,then , first column will be false, already intialzed
    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= target)
    {
        dp[0][arr[0]] =1;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= target; j++)
        {

            int not_pick = dp[i - 1][j];

            int pick = 0;

            if (arr[i] <= j)
            {
                pick = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = not_pick + pick;
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j <= target; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n - 1][target];*/

    int n = arr.size();
    int target = k;
    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);
    
    //first element of each row will be true bcz target==0
    curr[0] = prev[0] = 1;

    prev[arr[0]] = 1;

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= target; j++)
        {

            int not_pick = prev[j];

            int pick = 0;

            if (arr[i] <= j)
            {
                pick = prev[j - arr[i]];
            }

            curr[j] = not_pick + pick;
        }
        prev = curr;
    }

    return prev[target];
}

int main()
{

    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        arr.push_back(x);
    }

    int res = findWays(arr, k);
    cout << res << endl;
    return 0;
}