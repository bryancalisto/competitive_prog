#include <bits/stdc++.h>
using namespace std;

bool isSumEqual(string firstWord, string secondWord, string targetWord)
{
  string::iterator it;
  string tmp1 = "", tmp2 = "", tmp3 = "";

  for (it = firstWord.begin(); it != firstWord.end(); it++)
  {
    tmp1 += to_string((int)(*it) % 97);
  }

  for (it = secondWord.begin(); it != secondWord.end(); it++)
  {
    tmp2 += to_string((int)(*it) % 97);
  }

  for (it = targetWord.begin(); it != targetWord.end(); it++)
  {
    tmp3 += to_string((int)(*it) % 97);
  }

  if (stoi(tmp1) + stoi(tmp2) == stoi(tmp3))
  {
    return true;
  }

  return false;
}

int main()
{
  string firstWord = "acb", secondWord = "cba", targetWord = "cdb";
  cout << (isSumEqual(firstWord, secondWord, targetWord) ? "true" : "false");
}