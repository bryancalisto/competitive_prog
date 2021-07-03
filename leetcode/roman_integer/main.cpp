#include <bits/stdc++.h>

using namespace std;

typedef unsigned short int smalli;

class Solution
{
public:
  int romanToInt(string s)
  {
    int i, j, sum = 0, next;
    map<char, smalli> ht;
    ht['I'] = 1;
    ht['V'] = 5;
    ht['X'] = 10;
    ht['L'] = 50;
    ht['C'] = 100;
    ht['D'] = 500;
    ht['M'] = 1000;

    for (i = 0; i < s.size(); i++)
    {
      if (i + 1 < s.size())
      {
        next = ht[s[i + 1]];
        if (ht[s[i]] < next)
        {
          sum += next - ht[s[i]];
          i++;
        }
        else
        {
          sum += ht[s[i]];
        }
      }
      else
      {
        sum += ht[s[i]];
      }
    }

    return sum;
  }
};

int main()
{
  Solution sol;

  // string s = "IX";
  // string s = "XIX";
  // string s = "XIV";
  // string s = "MCMXCIV";
  // string s = "III";
  string s = "MDCXCV";

  printf("%d", sol.romanToInt(s));
}