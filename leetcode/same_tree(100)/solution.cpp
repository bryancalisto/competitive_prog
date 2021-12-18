#include <bits/stdc++.h>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    bool res = true;
    helper(p, q, &res);
    return res;
  }

  void helper(TreeNode *p, TreeNode *q, bool *res)
  {
    if (!p || !q)
    {
      if (!p ^ !q)
      {
        *res = false;
      }

      return;
    }

    // printf("p: %d , q: %d\n", p->val, q->val);
    if (p->val != q->val)
    {
      *res = false;
    }

    helper(p->left, q->left, res);
    helper(p->right, q->right, res);
  }
};

int main()
{
  Solution sol;
  TreeNode *rootA = &TreeNode(1, &TreeNode(2), &TreeNode(3));
  TreeNode *rootB = &TreeNode(1, &TreeNode(2), &TreeNode(4));
  cout << sol.isSameTree(rootA, rootB);
}