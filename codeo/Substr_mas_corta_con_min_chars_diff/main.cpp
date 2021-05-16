#include <bits/stdc++.h>

using namespace std;

int main()
{
  string str;
  int k, i = 0, j = 0, l = 0, minLen = 100000, len;
  map<char, int> tabla;

  cin >> str;
  cin >> k;

  while (j < str.length())
  {
    while (tabla.size() < k && j < str.length())
    {
      tabla[str[j]]++;
      j++;
    }

    while (tabla.size() == k && tabla[str[i]] > 1)
    {
      tabla[str[i]]--;
      i++;
    }

    if (tabla.size() >= k)
    {
      minLen = min(minLen, j - i);
    }

    while (tabla.size() == k)
    {
      tabla[str[i]]--;
      if (tabla[str[i]] <= 0)
      {
        tabla.erase(str[i]);
      }
      i++;
    }

    tabla[str[j]]++;
    j++;
  }

  cout << ((minLen == 100000) ? -1 : minLen);
  return 0;
}