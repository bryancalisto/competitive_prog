// https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/546/
#include <bits/stdc++.h>

using namespace std;

vector<int> split(const string &);

vector<int> twoSum(vector<int> &nums, int target)
{
  map<int, int> ht;
  int tmp;
  vector<int> res;
  ht[nums[0]] = 1; // index+1 to overcome the hashtable default value. I.E ht[someValue] = 0, when someValue was not in the hashtable

  for (int j = 1; j < nums.size(); j++)
  {
    tmp = target - nums[j];
    if (ht[tmp] > 0)
    {
      res.push_back(ht[tmp] - 1);
      res.push_back(j);
      ht[tmp]--;
      break;
    }

    ht[nums[j]] = j + 1;
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