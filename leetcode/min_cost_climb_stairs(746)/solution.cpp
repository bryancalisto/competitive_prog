// https://leetcode.com/problems/min-cost-climbing-stairs/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  int minCostClimbingStairs(vector<int> &cost)
  {
    int N = cost.size();
    vector<int> dp = vector<int>(N);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < N; i++)
    {
      dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }

    return min(dp[N - 1], dp[N - 2]);
  }
};

int main()
{
  Solution sol;
  // vector<int> cost{10, 15, 20};
  vector<int> cost{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
  cout << sol.minCostClimbingStairs(cost);
}