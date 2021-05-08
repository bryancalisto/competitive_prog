// https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem?h_l=interview&playlist_slugs%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D=strings
#include <bits/stdc++.h>

using namespace std;

string isValid(string s)
{
  map<char, int> chars;
  map<int, int> freq;
  string::iterator it;
  map<int, int>::iterator itFreq;
  map<int, int>::iterator prevFreq;

  for (it = s.begin(); it != s.end(); it++)
  {
    chars[*it]++;
  }

  for (auto c : chars)
  {
    freq[c.second]++;
  }

  if (freq.size() > 1)
  {
    prevFreq = freq.begin();
    itFreq = ++freq.begin();
    if (abs(prevFreq->first - itFreq->first) > 1 || itFreq->second > 1)
    {
      return "NO";
    }
  }

  return "YES";
}

int main()
{
  string s;
  getline(cin, s);
  string result = isValid(s);
  cout << result << "\n";
  return 0;
}
