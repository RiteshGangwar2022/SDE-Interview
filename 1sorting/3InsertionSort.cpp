#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr)
{

    for (int i = 1; i < arr.size(); i++)
    {

        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
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

    insertion_sort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}