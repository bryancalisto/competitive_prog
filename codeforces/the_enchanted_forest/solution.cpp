// https://codeforces.com/contest/1687/problem/A
#include <bits/stdc++.h>

using namespace std;

void solution()
{
  int n, k;
  cin >> n >> k;
  vector<int> mush(n), dp(n + 1, 0);

  for (int i = 0; i < n; i++)
  {
    cin >> mush[i];
  }

  for (int i = 0; i < n; i++)
  {
    dp[i + 1] = mush[i] + dp[i];
  }

  if (k < n)
  {
    int res = 0;

    for (size_t i = 0; i < n; i++)
    {
      // Size k groups sum of initial mushrooms + the grown mushrooms
      res = max(res, dp[i + 1] - dp[i + 1 + k] + k * (k - 1) / 2);
    }

    cout << res << endl;
  }
  else
  {
    // Initial mushrooms + all grown mushrooms (k * n) - the ones that don't have enough time to eat (all the n possibilities of grown mushrooms)
    cout << dp[n] + k * n - (n * (n + 1) / 2) << endl;
  }
}

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    solution();
  }
}