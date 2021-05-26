// https://leetcode.com/problems/jump-game-vii/
#include <bits/stdc++.h>

using namespace std;

bool canReach(string s, int minJump, int maxJump)
{
  int farthest = 0, start, i, j, k;
  deque<int> steps = {0};

  while (!steps.empty())
  {
    i = steps.back();
    steps.pop_back();
    start = max(i + minJump, farthest + 1);
    k = 0;

    for (j = start; j < min(i + maxJump + 1, (int)s.size()); j++)
    {
      if (s[j] == '0')
      {
        steps.push_front(j);
        if (j == s.size() - 1)
        {
          return true;
        }
      }
    }

    farthest = i + maxJump;
  }

  return false;
}

int main()
{
  string s;
  int minJump;
  int maxJump;
  bool res;

  // TESTS
  s = "01101110";
  minJump = 2;
  maxJump = 3;
  assert(canReach(s, minJump, maxJump) == false);

  s = "011010";
  minJump = 2;
  maxJump = 3;
  assert(canReach(s, minJump, maxJump) == true);
}