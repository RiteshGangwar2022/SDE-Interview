#include <bits/stdc++.h>
using namespace std;

/*int countPartitions(vector<int> &nums, int n, int target, vector<vector<int>> &dp)
{

    // below base condition1s will fail , nums contains 0 as elements
    /* if (target ==0)
     {
         return 1;
     }
     if (n == 0)
     {
         if (nums[0] == target)
         {
             return 1;
         }
         else
         {
             return 0;
         }
     }*/

// base case, if nums contains 0 as elements

/*if (n == 0)
{
    if (target == 0 && nums[0] == 0)
    {
        return 2;
    }
    if (target==0 || target == nums[0])
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

int not_pick = countPartitions(nums, n - 1, target, dp);

int pick = 0;

if (nums[n] <= target)
{
    pick = countPartitions(nums, n - 1, target - nums[n], dp);
}

return dp[n][target] = (pick + not_pick);
}*/

int findTargetSumWays(vector<int> &nums, int target)
{

    // this problem similar to count number of subset with given difference
    // and, here difference=target

    // count number of subset with given difference

    int n = nums.size();

    int sum = accumulate(nums.begin(), nums.end(), 0);

    int d = target;

    if ((sum - d) % 2 != 0)
    {
        return 0;
    }

    if ((sum - abs(d)) < 0)
    {
        return 0;
    }

    target = (sum + d) / 2;
    /*vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int res = countPartitions(nums, n - 1, target, dp);

    for(int i=0;i<n;i++){

        for(int j=0;j<=target;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
    return res;*/
    /* vector<vector<int>> dp(n, vector<int>(target + 1, 0));

     // base case

     if (nums[0] == 0)
     {
         dp[0][0] = 2;
     }
     else
     {
         dp[0][0] = 1;
     }

     if (nums[0] != 0 && nums[0] <= target)
     {
         dp[0][nums[0]] = 1;
     }

     for (int i = 1; i < n; i++)
     {

         for (int j = 0; j <= target; j++)
         {

             int not_pick = dp[i - 1][j];

             int pick = 0;

             if (nums[i] <= j)
             {
                 pick = dp[i - 1][j - nums[i]];
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

    vector<int> prev(target + 1, 0);
    vector<int> curr(target + 1, 0);

    // base case

    if (nums[0] == 0)
    {
        prev[0] = 2;
    }
    else
    {
        prev[0] = 1;
    }

    if (nums[0] != 0 && nums[0] <= target)
    {
        prev[nums[0]] = 1;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j <= target; j++)
        {

            int not_pick = prev[j];

            int pick = 0;

            if (nums[i] <= j)
            {
                pick = prev[j - nums[i]];
            }

            curr[j] = not_pick + pick;
        }
        prev = curr;
    }

    for (int j = 0; j <= target; j++)
    {
        cout << prev[j] << " ";
    }

    return prev[target];
}

int main()
{

    int n, target;
    cin >> n >> target;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        nums.push_back(x);
    }

    int res = findTargetSumWays(nums, target);
    cout << "total number of ways " << res << endl;

    return 0;
}