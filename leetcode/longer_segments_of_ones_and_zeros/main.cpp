#include <bits/stdc++.h>
using namespace std;

bool checkZeroOnes(string s)
{
  int i = 0, j = 0;
  map<char, int> ht;
  int ones = 0, zeros = 0;

  if (s == "1")
  {
    return true;
  }
  if (s == "0")
  {
    return false;
  }

  while (i < s.size() - 1)
  {
    j = i + 1;
    ht[s[i]] = 1;
    while (s[i] == s[j])
    {
      ht[s[i]]++;
      cout << ht[s[i]] << endl;
      j++;
    }

    if (s[i] == '1' && ht['1'] > ones)
    {
      ones = ht[s[i]];
    }

    if (s[i] == '0' && ht['0'] > zeros)
    {
      zeros = ht[s[i]];
    }

    i = j;
  }

  if (ones > zeros)
  {
    return true;
  }

  return false;
}

int main()
{
  string s;
  cin >> s;

  bool res = checkZeroOnes(s);
  cout << res << endl;
}