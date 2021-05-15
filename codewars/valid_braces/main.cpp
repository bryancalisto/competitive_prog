#include <bits/stdc++.h>

using namespace std;

bool valid_braces(std::string braces)
{
  stack<char> brac;
  string::iterator it;

  it = braces.begin();
  brac.push(*it);
  it++;

  for (it; it != braces.end(); it++)
  {
    if (brac.size() == 0)
    {
      brac.push(*it);
      continue;
    }

    switch (*it)
    {
    case ')':
      if (brac.top() == '(')
      {
        brac.pop();
      }
      else
      {
        brac.push(*it);
      }
      break;
    case ']':
      if (brac.top() == '[')
      {
        brac.pop();
      }
      else
      {
        brac.push(*it);
      }
      break;
    case '}':
      if (brac.top() == '{')
      {
        brac.pop();
      }
      else
      {
        brac.push(*it);
      }
      break;

    default:
      brac.push(*it);
      break;
    }
  }

  if (brac.size() > 0)
  {
    return false;
  }

  return true;
}

int main()
{
  string input;
  cin >> input;
  cout << (valid_braces(input) ? "true" : "false") << endl;
}