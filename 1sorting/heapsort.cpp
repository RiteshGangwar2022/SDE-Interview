#include <bits/stdc++.h>
using namespace std;

void max_heapify(vector<int> &arr, int size, int index)
{

    int parent_index = index;
    int left_index = 2 * parent_index + 1;
    int right_index = 2 * parent_index + 2;
    int max_index = parent_index;

    if (left_index < size && arr[left_index] > arr[max_index])
    {
        max_index = left_index;
    }
    if (right_index < size && arr[right_index] > arr[max_index])
    {
        max_index = right_index;
    }
    if (parent_index != max_index)
    {
        swap(arr[parent_index], arr[max_index]);
        max_heapify(arr, size, max_index);
    }
}

void build_heap(vector<int> &arr)
{

    int size = (arr.size() - 2) / 2;

    for (int i = size; i >= 0; i--)
    {

        max_heapify(arr,arr.size(), i);
    }
}

void heap_sort(vector<int> &arr)
{

    build_heap(arr);
    for(auto it:arr){
        cout<<it<<" ";
    }
    cout<<endl;

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
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

    heap_sort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}