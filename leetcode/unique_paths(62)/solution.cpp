#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int helper(int m, int n, map<string, int> &mem)
  {
    if (mem[to_string(m) + "," + to_string(n)] != 0)
    {
      return mem[to_string(m) + "," + to_string(n)];
    }

    if (m == 1 || n == 1)
    {
      return 1;
    }
    mem[to_string(m) + "," + to_string(n)] = helper(m - 1, n, mem) + helper(m, n - 1, mem);
    return mem[to_string(m) + "," + to_string(n)];
  }

  int uniquePaths(int m, int n)
  {
    map<string, int> mem;
    return helper(m, n, mem);
  }
};

int main()
{
  cout << Solution().uniquePaths(3, 7) << endl;
}