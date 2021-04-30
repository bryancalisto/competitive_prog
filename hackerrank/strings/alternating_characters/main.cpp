// https://www.hackerrank.com/challenges/alternating-characters/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings&h_r=next-challenge&h_v=zen

#include <bits/stdc++.h>
using namespace std;

int alternatingCharacters(string s)
{
  int i, res = 0;

  for (i = 0; i < s.length() - 1; i++)
  {
    if (s[i] == s[i + 1])
    {
      res++;
    }
  }

  return res;
}

int main()
{
  string q_temp;
  getline(cin, q_temp);

  int q = stoi(q_temp);

  for (int q_itr = 0; q_itr < q; q_itr++)
  {
    string s;
    getline(cin, s);

    int result = alternatingCharacters(s);

    cout << result << "\n";
  }

  return 0;
}

// GETS 100%