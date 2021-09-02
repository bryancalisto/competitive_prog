//https://leetcode.com/problems/permutations/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  vector<string> generateParenthesis(int n)
  {
    vector<string> res;
    _generate(res, "", 0, 0, n);
    return res;
  }

  void _generate(vector<string> &res, string s, int open, int closed, int n)
  {
    if (s.size() == 2 * n)
    {
      res.push_back(s);
    }

    if (open < n)
    {
      _generate(res, s + "(", open + 1, closed, n);
    }

    if (closed < open)
    {
      _generate(res, s + ")", open, closed + 1, n);
    }
  }
};

int main()
{
  Solution sol;
  vector<string> res;
  vector<string>::iterator it;
  int n = 4;

  res = sol.generateParenthesis(n);

  for (it = res.begin(); it < res.end(); it++)
  {
    cout << *it << endl;
  }
}