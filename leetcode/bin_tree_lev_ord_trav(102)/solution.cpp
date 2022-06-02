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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> res;
    queue<TreeNode *> q;

    if (!root)
    {
      return res;
    }

    q.push(root);

    while (!q.empty())
    {
      int nChildren = q.size();
      vector<int> vec;

      for (int i = 0; i < nChildren; i++)
      {
        TreeNode *node = q.front();
        q.pop();

        if (node)
        {
          vec.push_back(node->val);
          q.push(node->left);
          q.push(node->right);
        }
      }

      if (vec.size())
        res.push_back(vec);
    }

    return res;
  }
};