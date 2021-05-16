#include <bits/stdc++.h>

using namespace std;

int main()
{
  string input;
  int carry = 1;
  int tmp;

  cin >> input;

  string::reverse_iterator itr = input.rbegin(), final = input.rend();
  while (carry && itr != final)
  {
    tmp = (*itr - '0') + carry;
    carry = tmp / 10;
    *itr = (tmp % 10) + '0';
    itr++;
  }

  if (carry)
  {
    input.insert(0, "1");
  }

  cout << input << endl;
}