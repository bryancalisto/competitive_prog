#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int majorityElement(vector<int> &nums)
  {
    int count = 0;
    int res = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[i] == res)
      {
        count++;
      }
      else
      {
        count--;
        if (count == 0)
        {
          res = nums[i + 1];
        }
      }
    }

    return res;
  }
};

int main()
{
  Solution sol;
  vector<int> nums{2, 2, 1, 1, 1, 2, 2};
  cout << sol.majorityElement(nums);
}