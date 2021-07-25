//https://leetcode.com/problems/search-insert-position/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
public:
  int searchInsert(vector<int> &nums, int target)
  {
    int left, right, middle, res;
    left = 0;
    right = nums.size() - 1;

    while (right >= left)
    {
      middle = left + (right - left) / 2;

      if (nums[middle] == target)
      {
        return middle;
      }

      if (target > nums[middle])
      {
        res = middle + 1;
        left = middle + 1;
      }
      else
      {
        res = middle;
        right = middle - 1;
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  // vector<int> nums = {1, 3, 4, 5, 6, 7, 9};
  vector<int> nums = {1, 3, 5, 6};
  int target = 9;
  target = 4;
  printf("%d\n", sol.searchInsert(nums, target));
}