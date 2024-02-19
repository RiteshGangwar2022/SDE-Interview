#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int>&arr){

    for(int i=0;i<arr.size();i++){

        int temp=arr[i];
        int mini_index=i;

        for(int j=i+1;j<arr.size();j++){

            if(arr[j]<temp){
                temp=arr[j];
                mini_index=j;
            }
        }
        swap(arr[mini_index],arr[i]);
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

    selection_sort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}