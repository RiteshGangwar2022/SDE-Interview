#include <bits/stdc++.h>
using namespace std;

/*int min_path_sum_helper(int i, int j, vector<vector<int>> &triangle,vector<vector<int>>&dp)
{

    if (i < 0 || j < 0)
    {
        return INT_MAX;
    }

    if(i==0){
        return triangle[0][0];
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    int dia=min_path_sum_helper(i-1,j-1,triangle,dp);
    int up=min_path_sum_helper(i-1,j,triangle,dp);

    return dp[i][j]=triangle[i][j]+min(dia,up);
}*/
int min_path_sum(vector<vector<int>> &triangle)
{

    int n = triangle.size();

    /*int res = INT_MAX;
    vector<vector<int>>dp(n,vector<int>(n,-1));

    for (int i = n - 1; i >= 0; i--)
    {

        int temp = min_path_sum_helper(n - 1, i, triangle,dp);
        res = min(temp, res);
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return res;*/
  /*  vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

    for (int i = 0; i < n; i++)
    {
        dp[n - 1][i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {

        for (int j = i; j >= 0; j--)
        {

            int dia = dp[i + 1][j + 1];
            int up = dp[i + 1][j];

            dp[i][j] = triangle[i][j] + min(dia, up);
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
    return dp[0][0];*/

    vector<int>next(n,INT_MAX),curr(n,INT_MAX);
     for (int i = 0; i < n; i++)
    {
        next[i] = triangle[n - 1][i];
    }

    for (int i = n - 2; i >= 0; i--)
    {

        for (int j = i; j >= 0; j--)
        {

            int dia = next[j + 1];
            int up = next[j];

            curr[j] = triangle[i][j] + min(dia, up);
        }
        next=curr;
    }
  
        for (int j = 0; j < n; j++)
        {
            cout << next[j] << " ";
        }
        cout << endl;

    return next[0];
}
int main()
{

    int n;
    cin >> n;

    vector<vector<int>> triangle;
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            int x;
            cin >> x;
            temp.push_back(x);
        }
        triangle.push_back(temp);
    }

    /*for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        for (int j = 0; j <= i; j++)
        {
            cout << triangle[i][j] << " ";
        }
        cout << endl;
    }*/

    int min_sum = min_path_sum(triangle);
    cout << "min path sum " << min_sum << endl;

    return 0;
}