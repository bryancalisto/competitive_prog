#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> res;
    helper(numRows, res);
    return res;
  }

  void helper(int numRows, vector<vector<int>> &res)
  {
    if (numRows == 0)
    {
      return;
    }

    vector<int> newRow;

    for (int i = 0; i < numRows; i++)
    {
      newRow.insert(newRow.begin(), 1);

      for (int j = 1; j < newRow.size() - 1; j++)
      {
        newRow[j] = newRow[j] + newRow[j + 1];
      }
      res.push_back(newRow);
    }
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