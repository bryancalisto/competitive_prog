#include <bits/stdc++.h>

using namespace std;

vector<int> split(const string &);

int removeDuplicates(vector<int> &nums)
{
  if (nums.empty())
  {
    return 0;
  }

  int curr = nums[0];
  int i = 1;
  vector<int>::iterator it = nums.begin();

  while (i < nums.size())
  {
    if (curr == nums[i])
    {
      nums.erase(it + i);
    }
    else
    {
      curr = nums[i];
      i++;
    }
  }

  return nums.size();
}

int main(void)
{
  string nums;
  getline(cin, nums);

  vector<int> the_nums = split(nums);
  int res = removeDuplicates(the_nums);
  for (int i = 0; i < res; i++)
  {
    cout << the_nums[i] << endl;
  }
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