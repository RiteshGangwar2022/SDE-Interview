#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {

        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    int pivot_index = count + start;

    swap(arr[start], arr[pivot_index]);

    int left = start;
    int right = end;

    while (left < pivot_index && right > pivot_index)
    {

        while (arr[left] < pivot)
        {
            left++;
        }
        while (arr[right] > pivot)
        {
            right--;
        }

        if (left < pivot_index && right > pivot_index)
        {
            swap(arr[left], arr[right]);
        }
    }

    return pivot_index;
}

void quick_sort(vector<int> &arr, int start, int end)
{

    if (start >= end)
    {

        return;
    }

    int mid = start + (end - start) / 2;
    int p = partition(arr, start, end);
    quick_sort(arr, start, p - 1);
    quick_sort(arr, p + 1, end);
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

    quick_sort(arr, 0, arr.size() - 1);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}