#include <bits/stdc++.h>
using namespace std;

/*bool subsetSumToK_helper(vector<int> &arr, int n, int target, vector<vector<int>> &dp)
{

    if (target == 0)
    {
        return true;
    }

    if (n == 0)
    {

        if (arr[0] == target)
        {
            return true;
        }
        return false;
    }

    if (dp[n][target]!=-1)
    {
        return dp[n][target];
    }

    bool not_pick = subsetSumToK_helper(arr, n - 1, target, dp);

    bool pick = false;

    if (arr[n] <= target)
    {
        pick = subsetSumToK_helper(arr, n - 1, target - arr[n], dp);
    }

    return dp[n][target] = not_pick || pick;
}
*/

bool subsetSumToK(vector<int> &arr, int n, int k)
{

    /* int target = k;
     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
     bool res = subsetSumToK_helper(arr, n - 1, target, dp);

     for (int i = 0; i < n; i++)
     {

         for (int j = 0; j <= target; j++)
         {
             cout << dp[i][j] << " ";
         }
         cout << endl;
     }
     return res;

    /*int target = k;
    vector<vector<bool>> dp(n, vector<bool>(target + 1, 0));

    // base case=> if target==0, first colm, will be true

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    // base case=> if n==0,then , first column will be false, already intialzed
    // Base case: If the first element of 'arr' is less than or equal to 'k', set dp[0][arr[0]] to true
    if (arr[0] <= target)
    {
        dp[0][arr[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= target; j++)
        {

            bool not_pick = dp[i - 1][j];

            bool pick = false;

            if (arr[i] <= j)
            {
                pick = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = not_pick || pick;
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
    int target = k;
    vector<bool> prev(target + 1, 0);
    vector<bool> curr(target + 1, 0);

    // every row first element is mark as true
    prev[0] = true;
    curr[0] = true;
    prev[arr[0]] = true;

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= target; j++)
        {

            bool not_pick = prev[j];

            bool pick = false;

            if (arr[i] <= j)
            {
                pick = prev[j - arr[i]];
            }

            curr[j] = not_pick || pick;
        }
        prev = curr;
    }

    for (int j = 0; j <= target; j++)
    {
        cout << prev[j] << " ";
    }
    cout << endl;

    return prev[target];
}

bool equal_sum_parition(vector<int> &arr, int n)
{

    // just take sum of all the  element as the target,
    // if some is odd, can't do parition return false
    // else call, subet sum for=> target=sum/2;

    int sum = 0;

    for (auto it : arr)
    {
        sum += it;
    }

    if (sum % 2 != 0)
    {
        return false;
    }

    int k = sum / 2;
    bool res = subsetSumToK(arr, n, k);
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
    bool res = equal_sum_parition(arr, n);
    cout << res << endl;
    return 0;
}