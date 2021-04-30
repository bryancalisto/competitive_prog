//https://www.hackerrank.com/challenges/ctci-making-anagrams/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings

#include <bits/stdc++.h>

using namespace std;

int makeAnagram(string a, string b)
{
  int i, res = 0;
  map<char, int> table;

  for (i = 0; i < a.length(); i++)
  {
    table[a[i]]++;
  }

  for (i = 0; i < b.length(); i++)
  {
    table[b[i]]--;
  }

  for (auto t : table)
  {
    res += abs((long)t.second);
  }

  return res;
}

int main()
{
  string a;
  getline(cin, a);

  string b;
  getline(cin, b);

  int res = makeAnagram(a, b);
  cout << res << endl;

  return 0;
}

// GOT 100%