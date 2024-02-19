#include <bits/stdc++.h>
using namespace std;

/*int Area_histogram(vector<int> &height)
{

    int max_area=0;

    for(int i=0;i<height.size();i++){

        int left=i;

        while(left>=0 && height[i]<=height[left]){
            left--;
        }

        int right=i;

        while(right<height.size() && height[right]>=height[i]){
            right++;
        }

        int index=right-left-1;

        max_area=max(max_area,index*height[i]);
    }

    return max_area;

}*/

void previous_smaller_fn(vector<int> &pre_smaller, vector<int> &height)
{

    stack<pair<int, int>> s; //<element,index>
    int k = 0;
    for (int i = 0; i < height.size(); i++)
    {

        while (s.size() && s.top().first >= height[i])
        {
            s.pop();
        }
        if (s.size() == 0)
        {
            pre_smaller[k++] = -1;
        }
        else
        {
            pre_smaller[k++] = s.top().second; // put pre_smaller index
        }
        s.push({height[i], i});
    }
}
void next_smaller_fn(vector<int> &next_smaller, vector<int> &height)
{

    stack<pair<int, int>> s; //<element,index>
    int k = height.size() - 1;
    for (int i = height.size() - 1; i >= 0; i--)
    {

        while (s.size() && s.top().first >= height[i])
        {
            s.pop();
        }
        if (s.size() == 0)
        {
            next_smaller[k--] = height.size();
        }
        else
        {
            next_smaller[k--] = s.top().second; // put pre_smaller index
        }
        s.push({height[i], i});
    }
}

int Area_histogram(vector<int> height)
{

    // we will implement two functions , previous smaller and next smaller
    // rest formular remains same => (right-left-1)height[i]*

    vector<int> pre_smaller(height.size(), -1);
    previous_smaller_fn(pre_smaller, height);

    vector<int> next_smaller(height.size(), height.size());
    next_smaller_fn(next_smaller, height);

    int maxarea = 0;

    for (int i = 0; i < height.size(); i++)
    {

        int tempans = (next_smaller[i] - pre_smaller[i] - 1) * height[i];
        maxarea = max(maxarea, tempans);
    }

    return maxarea;
}
int main()
{
    int n;
    cin >> n;

    vector<int> heights;

    for (int i = 0; i < n; i++)
    {

        int x;
        cin >> x;
        heights.push_back(x);
    }

    int max_area = Area_histogram(heights);
    cout << "max area " << max_area << endl;

    return 0;
}