#include <bits/stdc++.h>
using namespace std;

int min_subset_partition(vector<int> &nums, int target)
{

    int n = nums.size();

    // bool res=subset_sum_helper(n-1,nums,target);

    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // base condition
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }

    if (nums[0] <= target)
    {

        dp[0][nums[0]] = true;
    }

    for (int i = 1; i < n; i++)
    {

        for (int j = 1; j <= target; j++)
        {

            bool not_pick = dp[i - 1][j];

            bool pick = false;

            if (nums[i] <= j)
            {

                pick = dp[i - 1][j - nums[i]];
            }

            dp[i][j] = pick || not_pick;
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

    // now, we can calculate minmum subset_sum difference, by evaluating all the posibilities, which are marked as true for last row of dp

    int res = INT_MAX;

    for (int i = 0; i <= target; i++)
    {

        if (dp[n - 1][i] == true)
        {

            int tempans = abs(i - (target - i));
            res = min(res, tempans);
        }
    }
    return res;
}
int minimumDifference(vector<int> &nums)
{

    int sum = 0;

    for (auto it : nums)
    {

        sum += it;
    }

    int target = sum;

    int res = min_subset_partition(nums, target);

    return res;
}

int main()
{

    int n;
    cin >> n;

    vector<int> nums;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        nums.push_back(x);
    }

    int res = minimumDifference(nums);
    cout << "min-difference " << res << endl;

    return 0;
}