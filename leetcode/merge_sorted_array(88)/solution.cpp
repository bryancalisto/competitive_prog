#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
  {
    int indexToInsert = 0;

    if (m == 0)
    {
      // nums1.insert(nums1.begin(), nums2.begin(), nums2.end());
      nums1 = nums2;
      return;
    }

    for (int i = 0; i < n; i++)
    {
      nums1.pop_back();
    }

    for (int i = 0; i < n; i++)
    {
      while (indexToInsert < nums1.size() && nums2[i] >= nums1[indexToInsert])
      {
        indexToInsert++;
      }

      // nums1[indexToInsert] = nums2[i];
      nums1.insert(nums1.begin() + indexToInsert, nums2[i]);
    }
  }
};

int main()
{
  Solution sol;
  vector<int> nums1 = {1, 2, 3, 0, 0, 0};
  vector<int> nums2 = {4, 5, 6};
  // vector<int> nums1 = {1, 4, 5, 0, 0, 0};
  // vector<int> nums2 = {2, 3, 6};

  sol.merge(nums1, 3, nums2, 3);

  for (auto n : nums1)
  {
    cout << n << endl;
  }
}