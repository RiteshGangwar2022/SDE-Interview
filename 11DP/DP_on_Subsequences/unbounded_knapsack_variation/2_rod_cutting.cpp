#include <bits/stdc++.h>
using namespace std;

int cutRod_helper(vector<int> &price, vector<int> &weight, int n, int maxWeight)
{

    // base case

    if(maxWeight==0){
        return 0;
    }
    if (n==0)
    {
        return (maxWeight/weight[0])*price[0];
    }

    // not pick
    int not_pick = cutRod_helper(weight, price, n - 1, maxWeight);

    // pick
    int pick =INT_MIN;
    if (weight[n] <= maxWeight)
    {
        // only difference between 0/1 and unbounded knapsack is that, we will not move to previous index on taking the profit
        pick = price[n] + cutRod_helper(weight, price, n, maxWeight - weight[n]);
    }
    return max(pick, not_pick);
}
int cutRod(vector<int> &price, int n)
{
    // it is the just the variation of unbounded knapsack

    // here weight will length of rod

    vector<int> weight;

    for (int i = 1; i <= n; i++)
    {
        weight.push_back(i);
    }
    // and, max weight will be => length of rod
    int maxWeight = n;
    int res = cutRod_helper(price, weight, n-1, maxWeight);
    cout<<"res "<<res<<endl;
    return res;
}

int main()
{

    int n;
    cin >> n;

    vector<int> price;

    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        price.push_back(x);
    }

    int max_profit = cutRod(price, n);
    cout << "max possible profit " << max_profit << endl;

    return 0;
}