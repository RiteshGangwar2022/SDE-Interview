#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> &arr)
{

    for (int i = 0; i < arr.size(); i++)
    {

        for (int j = 0; j < arr.size() - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main()
{

    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    bubble_sort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}