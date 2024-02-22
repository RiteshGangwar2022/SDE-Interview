#include <bits/stdc++.h>
using namespace std;

int helper(int index, vector<int> &arr, int k, vector<int> &dp)
{

    if (index == arr.size())
    {
        return 0;
    }

    if (dp[index] != -1)
    {
        return dp[index];
    }

    int n = arr.size();

    int maxi = INT_MIN;
    int len = 0;
    int res = INT_MIN;

    for (int i = index; i < min(index + k, n); i++)
    {
        // will are taking a len variable to keep track lenght of partition
        len++;
        maxi = max(maxi, arr[i]); // maximum element in that partition
        int tempans = len * maxi + helper(i + 1, arr, k, dp);
        res = max(res, tempans);
    }
    return dp[index] = res;
}

int maximumSubarray(vector<int> &arr, int k)
{

    // we need to partition the arr at most of size k
    // in that partitioned subarray, we need to intialized all the elements with its maximum element in that parition
    // doing above operation we need to maximise the sum

    // we will used front partitoin  in it

    int n=arr.size();

    vector<int> dp(n + 1, -1);
    int res = helper(0, arr, k, dp);
    return res;
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

    int res = maxSumAfterPartitioning(arr, k);
    cout << "largest possible sum " << res << endl;
    return 0;
}