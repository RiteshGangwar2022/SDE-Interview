#include <bits/stdc++.h>
using namespace std;

/*int countPartitions_helper(int n, vector<int> &arr, int target, vector<vector<int>> &dp)
{

    /*4 10
  0 0 3 6
  =>according to below test cases , we will be getting wrong answer if array elements also inlcudes 0*/
/*if (target == 0)
{
    return 1;
}
if (n == 0)
{

    if (arr[0] == target)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}*/

// base cases, if array also contains the 0 elements

/* if (n == 0)
 {

     if (target == 0 && arr[0] == 0)
     {
         return 2;
     }
     else if (target == 0 || arr[0] == target)
     {
         return 1;
     }
     else
     {
         return 0;
     }
 }

 if (dp[n][target] != -1)
 {
     return dp[n][target];
 }

 // not_take
 int not_pick = countPartitions_helper(n - 1, arr, target, dp);

 // pick
 int pick = 0;
 if (arr[n] <= target)
 {
     pick = countPartitions_helper(n - 1, arr, target - arr[n], dp);
 }
 return dp[n][target] = (pick + not_pick);
}*/

int countPartitions(int n, int d, vector<int> &arr)
{

    // lets consider two subset=>explained in copy
    // s1 and s2
    // s1+s2=sum of arr
    // s1-s2=target(diff), as required in question
    // combining both the equations
    // 2*s1=sum+target=> s1=>(sum+target)/2=>k
    // so, question reduce to ,count number of subet with k

    int sum = accumulate(arr.begin(), arr.end(), 0); // sum all the elements of arr

    // edge cases =>in these we can not partition array
    if ((sum - d) < 0)
    {
        return 0;
    }
    if ((sum - d) % 2 != 0)
    {
        return 0;
    }

    // new target
    int target = (sum + d) / 2;

    /* vector<vector<int>> dp(n, vector<int>(target + 1, -1));
     int res = countPartitions_helper(n - 1, arr, target, dp);
     for (int i = 0; i < n; i++)
     {

         for (int j = 0; j < target + 1; j++)
         {
             cout << dp[i][j] << " ";
         }
         cout << endl;
     }
     return res;*/

    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // base cases
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }

    if (arr[0] != 0 && arr[0] <= target)
    {
        dp[0][arr[0]] = 1;
    }

    // base case if array contains the 0 as elements

    if (target == 0 && arr[0] == 0)
    {
        dp[0][0] = 2;
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

        for (int j = 0; j < target + 1; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n - 1][target];
}
int main()
{

    int n, target;
    cin >> n >> target;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        arr.push_back(x);
    }
    int res = countPartitions(n, target, arr);
    cout << "subset with given diff " << res << endl;
    return 0;
}