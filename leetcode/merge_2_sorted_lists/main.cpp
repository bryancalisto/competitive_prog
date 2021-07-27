// https://leetcode.com/problems/merge-two-sorted-lists/
#include <bits/stdc++.h>

using namespace std;

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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
  {
    ListNode merged = ListNode();
    ListNode *ptr = &merged; // Initialize merged list

    while (l1 != nullptr && l2 != nullptr)
    {
      if (l1->val < l2->val)
      {
        ptr->next = l1;
        l1 = l1->next;
      }
      else
      {
        ptr->next = l2;
        l2 = l2->next;
      }

      ptr = ptr->next;
    }

    ptr->next = l1 ? l1 : l2;

    return merged.next;
  }
};

int main()
{
  ListNode *l1_1 = new ListNode(1);
  ListNode *l1_2 = new ListNode(2);
  ListNode *l1_3 = new ListNode(4);

  l1_1->next = l1_2;
  l1_2->next = l1_3;

  ListNode *l2_1 = new ListNode(1);
  ListNode *l2_2 = new ListNode(2);
  ListNode *l2_3 = new ListNode(4);

  l2_1->next = l2_2;
  l2_2->next = l2_3;

  Solution sol;
  ListNode *res = sol.mergeTwoLists(l1_1, l2_1);

  // while (l1_1 != nullptr)
  // {
  //   printf("%d\n", l1_1->val);
  //   printf("AA\n");
  //   l1_1 = l1_1->next;
  // }

  while (res != nullptr)
  {
    printf("%d\n", res->val);
    res = res->next;
  }

  delete l1_1;
  delete l1_2;
  delete l1_3;
  delete l2_1;
  delete l2_2;
  delete l2_3;
}