#include <bits/stdc++.h>

using namespace std;

int main()
{
  int i, len, max = -1;
  string str, left = "", right = "";
  cin >> str;
  len = str.length();

  for (i = 0; i < len - 1; i++)
  {
    left += str[i];
    right.insert(0, 1, str[len - i - 1]);
    if (left == right)
    {
      if (i > max)
      {
        max = i;
      }
    }
  }

  cout << max + 1;
}