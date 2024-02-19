#include <bits/stdc++.h>
using namespace std;

                        
void merg(vector<int> &arr, int start, int mid, int end)
{

    int size = end - start + 1;

    vector<int> temp(size,0);

    int left = start;
    int new_start = start;
    int right = mid + 1;

    while (left <= mid && right <= end)
    {

        if (arr[left] > arr[right])
        {
            temp[new_start++] = arr[right++];
        }
        else
        {
            temp[new_start++] = arr[left++];
        }
    }

    while (left <= mid)
    {
        temp[new_start++] = arr[left++];
    }

    while (right <= end)
    {
        temp[new_start++] = arr[right++];
    }

    for (int x = start; x <= end; x++)
    {   
        cout<<temp[x]<<" ";
        arr[x] = temp[x];
    }
    cout<<endl;
}


void merg_sort(vector<int> &arr, int start, int end)
{

    if (start >= end)
    {
        return;
    }

    int mid = start + (end - start) / 2;
    merg_sort(arr, start, mid);
    merg_sort(arr, mid + 1, end);
    merg(arr, start, mid, end);

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

    merg_sort(arr, 0, arr.size() - 1);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}






