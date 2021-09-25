#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr){};
  ListNode(int x) : val(x), next(nullptr){};
  ListNode(int x, ListNode *next) : val(x), next(next){};
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode *removeElements(ListNode *head, int val)
  {
    if (!head)
    {
      return nullptr;
    }

    if (head->val == val)
    {
      ListNode *nextNode = head->next;
      delete head;
      return removeElements(nextNode, val);
    }

    head->next = removeElements(head->next, val);
    return head;
  }
};

int main()
{
  Solution sol;
  ListNode *list = new ListNode(2, new ListNode(3, new ListNode(3)));
  list = sol.removeElements(list, 3);

  if (!list)
  {
    printf("lista vacia\n");
  }

  while (list)
  {
    printf("%d\n", list->val);
    list = list->next;
  }
}