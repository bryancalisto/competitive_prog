// https://leetcode.com/problems/single-number/submissions/
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  // int singleNumber(vector<int> &nums)
  // {
  //   map<int, int> ht;
  //   int current;
  //   int number = 0;
  //   for (int i = 0; i < nums.size(); i++)
  //   {
  //     current = nums[i];
  //     if (ht[current] == 0)
  //     {
  //       number += current;
  //       ht[current] = 1;
  //     }
  //     else
  //     {
  //       number -= current;
  //       ht.erase(current);
  //     }
  //   }
  //   return number;
  // }
  int singleNumber(vector<int> &nums)
  {
    int number = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      number = number ^ nums[i];
    }

    return number;
  }
};

int main()
{
  // vector<int> nums = {4, 1, 2, 1, 2};
  vector<int> nums = {2, 2, 1};
  Solution sol;
  printf("%d\n", sol.singleNumber(nums));
}