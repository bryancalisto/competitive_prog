// https://leetcode.com/problems/jump-game-vii/
#include <bits/stdc++.h>

using namespace std;

bool canReach(string s, int minJump, int maxJump)
{
  queue<int> steps;
  int farthest = 0, start = 0, i, j;
  steps.push(0);

  while (!steps.empty())
  {
    i = steps.front();
    steps.pop();
    start = max(i + minJump, farthest + 1);

    for (j = start; j < min(i + maxJump + 1, (int)s.length()); j++)
    {
      if (s[j] == '0')
      {
        steps.push(j);
        if (j == s.length() - 1)
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