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

void previous_smaller_fn(vector<int>&pre_smaller){

   
     
}
void next_smaller_fn(vector<int>&next_smaller){

     
}

int Area_histogram(vector<int>height){

      //we will implement two functions , previous smaller and next smaller
      //rest formular remains same => (right-left-1)height[i]*

      vector<int>pre_smaller(height.size(),-1);
      previous_smaller_fn(pre_smaller);

      vector<int>next_smaller(height.size(),height.size());
      next_smaller_fn(next_smaller);

      int maxarea=0;

      for(int i=0;i<height.size();i++){

           int tempans=(next_smaller[i]-pre_smaller[i]-1)*height[i];
           maxarea=max(maxarea,tempans);
      }

     return maxarea;
}
int find_max_rectangle(vector<vector<char>> &grid)
{

    int max_area = 0;

    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> height(cols, 0);
    for (int row = 0; row < rows; row++)
    {

        for (int col = 0; col < cols; col++)
        {

            if ((grid[row][col] - '0') == 0)
            {
                height[col] = 0;
            }
            else
            {
                height[col]++;
            }
        }
        int area = Area_histogram(height);
        max_area = max(max_area, area);
    }

    return max_area;
}
int main()
{

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid;

    for (int i = 0; i < n; i++)
    {

        vector<char> row;
        for (int j = 0; j < m; j++)
        {

            char ch;
            cin >> ch;
            row.push_back(ch);
        }
        grid.push_back(row);
    }

    int max_rectangle = find_max_rectangle(grid);
    cout << "maximum possible rectangle " << max_rectangle << endl;
    return 0;
}