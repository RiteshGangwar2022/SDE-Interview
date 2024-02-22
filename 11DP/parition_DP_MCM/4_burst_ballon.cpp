#include <bits/stdc++.h>
using namespace std;


//to get better understansing read , striver article
int maxCoins(int i, int j, vector<int> &nums,vector<vector<int>>&dp)
{

    if(i>j){
        return 0;
    }


    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    

    int res=INT_MIN;

    for(int k=i;k<=j;k++){
       
        int tempans=nums[i-1]*nums[k]*nums[j+1]+maxCoins(i,k-1,nums,dp)+maxCoins(k+1,j,nums,dp);
        res=max(res,tempans);
    }

    return dp[i][j]=res;
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

    // we are doing this so,nums remain in bound bcz at index -1 and n, cost will be 1
    nums.push_back(1); // to insert 1 at last
    nums.insert(nums.begin(), 1);
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    int cost = maxCoins(1, n, nums,dp);
    cout << "total cost " << cost << endl;

    return 0;
}