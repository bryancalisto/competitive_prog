#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
  void deleteNode(ListNode *node)
  {
    while (node->next->next)
    {
      node->val = node->next->val;
      node = node->next;
    }

    node->val = node->next->val;
    delete node->next;
    node->next = NULL;
  }
};

int main()
{
  Solution sol;
  ListNode *root = new ListNode(4);
  root->next = new ListNode(5);
  root->next->next = new ListNode(1);
  root->next->next->next = new ListNode(9);
  root->next->next->next->next = nullptr;
  ListNode *toDelete = root->next;

  sol.deleteNode(toDelete);

  while (root)
  {
    cout << root->val << endl;
    root = root->next;
  }
}