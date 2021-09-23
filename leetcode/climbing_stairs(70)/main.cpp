// https://leetcode.com/problems/climbing-stairs/
#include <bits/stdc++.h>
#define FOR(i, start, end, step) for (int i = start; i < end; i += step)

using namespace std;

class Solution
{
public:
  int stairs;
  int _climbStairs(int i, map<int, int> &mem)
  {
    int count = 0;

    if (mem.count(i))
      return mem[i];

    if (i >= stairs)
      return 1;

    count += _climbStairs(i + 1, mem) + _climbStairs(i + 2, mem);

    mem[i] = count;
    return count;
  }

  int climbStairs(int n)
  {
    stairs = n - 1; // last stair
    map<int, int> mem;
    return _climbStairs(0, mem);
  }
};

int main()
{
  int n;
  cin >> n;
  Solution sol;
  printf("%d\n", sol.climbStairs(n));
}