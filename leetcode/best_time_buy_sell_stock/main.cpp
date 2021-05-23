#include <bits/stdc++.h>

using namespace std;

vector<int> split(const string &);

int maxProfit(vector<int> &prices)
{
  int profit = 0;

  for (int i = 1; i < prices.size(); i++)
  {
    if (prices[i] > prices[i - 1])
    {
      // Adding this difference is like adding the slopes of every increasing price interval
      profit += prices[i] - prices[i - 1];
    }
  }

  // printf("profit: %d\n", profit);
  return profit;
}

int main(void)
{
  string nums;
  getline(cin, nums);

  vector<int> the_nums = split(nums);
  int res = maxProfit(the_nums);
  // for (int i = 0; i < res; i++)
  // {
  //   cout << the_nums[i] << endl;
  // }
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