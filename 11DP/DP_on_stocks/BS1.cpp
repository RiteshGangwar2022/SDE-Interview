#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &prices)
{

    int profit = 0;
    int min_cost = prices[0];

    for (int i = 1; i < prices.size(); i++)
    {

        int temp_cost = prices[i] - min_cost;
        profit = max(profit, temp_cost);
        min_cost = min(min_cost, prices[i]);
    }

    return profit;
}
int main()
{
    int n;
    cin >> n;
    vector<int> prices;
    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        prices.push_back(x);
    }

    int max_profit=helper(prices);
    cout<<max_profit<<endl;
    return 0;
}