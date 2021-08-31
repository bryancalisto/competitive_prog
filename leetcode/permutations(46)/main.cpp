//https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> permute(vector<int> &nums)
  {
    vector<vector<int>> result;
    vector<int> currentSet;

    return _permute(nums, currentSet, result);
  }

  vector<vector<int>> _permute(vector<int> &nums, vector<int> &currentSet, vector<vector<int>> &answer)
  {
    if (nums.size() == 0)
    {
      answer.push_back(currentSet);
    }

    for (int i = 0; i < nums.size(); i++)
    {
      vector<int> newNums = nums;
      newNums.erase(newNums.begin() + i);
      currentSet.push_back(nums[i]);
      _permute(newNums, currentSet, answer);
      currentSet.pop_back();
    }

    return answer;
  }
};

int main()
{
  Solution sol;
  // vector<int> nums = {1, 3, 4, 5, 6, 7, 9};
  // vector<int> nums = {1, 3, 5, 6};
  vector<int> nums = {1, 2, 3};
  // vector<int> nums = {};
  vector<vector<int>> res = sol.permute(nums);

  for (int i = 0; i < res.size(); i++)
  {
    for (int j = 0; j < res[0].size(); j++)
    {
      cout << res[i][j] << endl;
    }
    cout << "===\n";
  }
}