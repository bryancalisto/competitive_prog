// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
#include <bits/stdc++.h>

using namespace std;

vector<int> split(const string &);

vector<vector<int>> threeSum(vector<int> &nums)
{
  int i = 0, tmp, low, high, sum;
  vector<vector<int>> res;

  if (nums.size() < 3)
  {
    return res;
  }

  sort(nums.begin(), nums.end());

  for (i = 0; i < nums.size() - 2; i++)
  {
    if (i > 0 && (nums[i] == nums[i - 1]))
    {
      continue;
    }

    low = i + 1;
    high = nums.size() - 1;
    tmp = 0 - nums[i];

    while (low < high)
    {
      sum = nums[low] + nums[high];
      if (sum == tmp)
      {
        vector<int> pair = {nums[i], nums[low], nums[high]};
        res.push_back(pair);
        // printf("[i=%d, low=%d, high=%d]\n", i, low, high);
        // printf("[%d, %d, %d]\n", nums[i], nums[low], nums[high]);

        while (low < high && nums[low] == nums[low + 1])
          low++;
        while (low < high && nums[high] == nums[high - 1])
          high--;

        low++;
        high--;
      }
      else if (sum > tmp)
      {
        high--;
      }
      else
      {
        low++;
      }
    }
  }

  return res;
}

int main(void)
{
  string nums;
  getline(cin, nums);

  vector<int> the_nums = split(nums);
  vector<vector<int>> res = threeSum(the_nums);
}

vector<int> split(const string &str)
{
  vector<int> tokens;

  string::size_type start = 0;
  string::size_type end = 0;

  while ((end = str.find(" ", start)) != string::npos)
  {
    tokens.push_back(stoi(str.substr(start, end - start)));
    start = end + 1;
  }

  tokens.push_back(stoi(str.substr(start)));

  return tokens;
}