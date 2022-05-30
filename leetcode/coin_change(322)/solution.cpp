#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int coinChange(vector<int> &coins, int amount)
  {
    int dpSize = amount + 1;
    vector<int> dp(dpSize, amount + 1);

    dp[0] = 0;

    for (int am = 1; am < dpSize; am++)
    {
      for (auto &coin : coins)
      {
        if (am - coin >= 0)
        {
          dp[am] = min(dp[am], dp[am - coin] + 1);
        }
      }
    }

    return dp[amount] == amount + 1 ? -1 : dp[amount];
  }
};