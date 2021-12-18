#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> res;
    vector<int> first = {1};

    res.push_back(first);
    if (numRows == 1)
    {
      return res;
    }

    vector<int> second = {1, 1};
    res.push_back(second);
    if (numRows == 2)
    {
      return res;
    }

    for (int i = 2; i < numRows; i++)
    {
      vector<int> row = {1};
      for (int j = 1; j < i; j++)
      {
        row.push_back(res[i - 1][j - 1] + res[i - 1][j]);
      }
      row.push_back(1);
      res.push_back(row);
    }

    return res;
  }
};

int main()
{
  Solution sol;
  int rows = 5;
  vector<vector<int>> res = sol.generate(rows);
  for (auto vect : res)
  {
    for (auto num : vect)
    {
      cout << num << " ";
    }
    cout << endl;
  }
  return 0;
}