#include <bits./stdc++.h>

using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int left, right, area = 0;

    left = 0;
    right = height.size();

    while (left < right)
    {
      area = max(area, min(height[left], height[right]) * (right - left));

      if (height[left] > height[right])
      {
        right--;
      }
      else
      {
        left++;
      }
    }

    return area;
  }
};

int main()
{
  Solution sol;
  // vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  // vector<int> height = {4, 3, 2, 1, 4};
  // vector<int> height = {1, 2};
  vector<int> height = {1, 2, 1};
  cout << sol.maxArea(height) << endl;
}