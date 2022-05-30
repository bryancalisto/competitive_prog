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
  int sumOfLeftLeaves(TreeNode *root)
  {
    int sum = 0;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
      TreeNode *current = q.front();
      q.pop();

      if (current->left)
      {
        q.push(current->left);
        if (!current->left->left && !current->left->right)
        {
          sum += current->left->val;
        }
      }

      if (current->right)
        q.push(current->right);
    }

    return sum;
  }
};