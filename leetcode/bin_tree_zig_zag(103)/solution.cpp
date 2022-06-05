#include <bits/stdc++.h>
using namespace std;

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
  vector<vector<int>> zigzagLevelOrder(TreeNode *root)
  {
    bool leftToRight = true;
    vector<vector<int>> res;

    if (!root)
      return res;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      vector<int> level;
      int nChildren = q.size();

      for (int i = 0; i < nChildren; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        level.push_back(node->val);

        if (node->left)
          q.push(node->left);
        if (node->right)
          q.push(node->right);
      }

      if (!leftToRight)
      {
        reverse(level.begin(), level.end());
      }

      if (level.size())
      {
        res.push_back(level);
      }

      leftToRight = !leftToRight;
    }

    return res;
  }
};