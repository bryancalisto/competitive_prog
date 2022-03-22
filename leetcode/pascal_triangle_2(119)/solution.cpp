#include <bits/stdc++.h>
#include <stack>
#include <deque>
using namespace std;

class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    if (rowIndex == 0)
    {
      return vector<int>{1};
    }
    if (rowIndex == 1)
    {
      return vector<int>{1, 1};
    }

    deque<int> prevNums;
    deque<int> newNums;
    vector<int> res;
    int num = 0;
    int current;
    int previous;
    int tempRes;

    prevNums.push_back(1);

    for (int i = 2; i <= rowIndex; i++)
    {
      prevNums.push_front(1);
      while (newNums.size())
      {
        prevNums.push_front(newNums.front());
        newNums.pop_front();
      }

      while (prevNums.size())
      {
        previous = prevNums.back();
        prevNums.pop_back();

        if (!prevNums.empty())
        {
          current = prevNums.back();
          tempRes = current + previous;
          newNums.push_back(tempRes);
          current = tempRes;
        }
      }

      if (i % 2 != 0)
      {
        newNums.push_back(current);
      }
    }

    // Build the result vector
    res.push_back(1);

    while (newNums.size())
    {
      current = newNums.front();
      newNums.pop_front();
      res.push_back(current);
      prevNums.push_back(current);
    }

    if (rowIndex % 2 != 0)
    {
      prevNums.pop_back();
      prevNums.pop_back();
    }
    else
    {
      prevNums.pop_back();
    }

    while (prevNums.size())
    {
      current = prevNums.back();
      prevNums.pop_back();
      res.push_back(current);
    }

    res.push_back(1);

    return res;
  }
};

int main()
{
  Solution sol;
  int index = 5;
  vector<int> res = sol.getRow(index);
  vector<int>::iterator itr;

  for (itr = res.begin(); itr != res.end(); itr++)
  {
    cout << *itr << endl;
  }
}