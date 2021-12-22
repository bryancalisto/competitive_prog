#include <bits/stdc++.h>

using namespace std;
/**
 * Definition for singly-linked list.
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    map<int, int> tbl;
    ListNode *current = head;

    while (current)
    {
      if (current->next)
      {
        if (current->val == current->next->val)
        {
          ListNode *nextNext = current->next->next;
          delete current->next;
          current->next = nextNext;
          if (!current->next)
          {
            current = current->next;
          }
        }
        else
        {
          current = current->next;
        }
      }
      else
      {
        current = current->next;
      }
    }

    return head;
  }
};

int main()
{
  Solution sol;

  // ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3)))));
  // ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2)));
  ListNode *head = new ListNode(1, new ListNode(1, new ListNode(2)));
  // ListNode *head = new ListNode(1, new ListNode(1, new ListNode(1)));

  ListNode *res = sol.deleteDuplicates(head);

  while (res)
  {
    printf("> %d\n", res->val);
    res = res->next;
  }

  delete head;
}