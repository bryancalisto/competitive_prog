#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<int> searchRange(vector<int> &nums, int target)
  {
    vector<int> res = {-1, -1};

    if (nums.size() == 0)
      return res;

    int left = 0;
    int right = nums.size() - 1;
    int middle;
    bool foundFirst = false;

    while (left <= right)
    {
      middle = left + (right - left) / 2;

      if (nums[middle] >= target)
      {
        right = middle - 1;
      }
      else
      {
        left = middle + 1;
      }

      if (nums[middle] == target)
        res[0] = middle;
    }

    if (res[0] == -1)
      return res;
    // printf("MID %d\n",middle);

    left = middle;
    right = nums.size() - 1;

    printf("left %d right %d\n", left, right);

    while (left <= right)
    {
      middle = left + (right - left) / 2;

      if (nums[middle] <= target)
      {
        left = middle + 1;
      }
      else
      {
        right = middle - 1;
      }

      if (nums[middle] == target)
        res[1] = middle;
    }

    return res;
  }
};