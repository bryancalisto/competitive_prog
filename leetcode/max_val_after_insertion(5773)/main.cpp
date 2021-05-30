#include <bits/stdc++.h>
using namespace std;

string maxValue(string n, int x)
{
  int j = n.size() - 1;
  int k = 0;

  if (n[0] == '-')
  {
    for (int i = 1; i < n.size(); i++)
    {
      if ((n[i] - '0') > x)
      {
        n.insert(i, to_string(x));
        return n;
      }
    }
    return n + to_string(x);
  }
  else
  {
    for (int i = 0; i < n.size(); i++)
    {
      if (n[i] - '0' < x)
      {
        n.insert(i, to_string(x));
        return n;
      }
    }
  }

  n.insert(n.size(), to_string(x));
  return n;
}

int main()
{
  string str;
  cin >> str;
  int x;
  cin >> x;
  cout << maxValue(str, x);
}