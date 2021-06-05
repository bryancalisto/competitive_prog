// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
#include <bits/stdc++.h>

using namespace std;

vector<int> split(const string &);

vector<int> twoSum(vector<int> &nums, int target)
{
  vector<int> res = {0, 0};
  int tmp;
  map<int, int> ht;

  ht[nums[0]] = 1;

  for (int i = 1; i < nums.size(); i++)
  {
    tmp = target - nums[i];

    if (ht[tmp] > 0)
    {
      res[0] = ht[tmp] - 1;
      res[1] = i;
      printf("res[0]=%d res[1]=%d\n", res[0], res[1]);
      break;
    }
    ht[nums[i]] = i + 1;
  }

  return res;
}

int main(void)
{
  string nums;
  int target;
  getline(cin, nums);
  scanf(" %d", &target);

  vector<int> the_nums = split(nums);
  twoSum(the_nums, target);
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