// https://leetcode.com/problems/climbing-stairs/
#include <bits/stdc++.h>
#define FOR(i, start, end, step) for (int i = start; i < end; i += step)

using namespace std;

class Solution
{
public:
  map<int, int> mem;

  int climbStairs(int n)
  {
    if (mem[n])
    {
      return mem[n];
    }

    if (n == 0)
    {
      return 1;
    }

    if (n < 0)
    {
      return 0;
    }

    int res = climbStairs(n - 1) + climbStairs(n - 2);
    mem[n] = res;
    return res;
  }
};

int main()
{
  int n;
  cin >> n;
  Solution sol;
  printf("%d\n", sol.climbStairs(n));
}