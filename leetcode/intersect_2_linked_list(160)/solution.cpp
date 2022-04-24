#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    map<ListNode *, int> tbl;
    ListNode *ptrA = headA;
    ListNode *ptrB = headB;

    while (ptrA)
    {
      tbl[ptrA]++;
      ptrA = ptrA->next;
    }

    while (ptrB)
    {
      tbl[ptrB]++;

      if (tbl[ptrB] > 1)
      {
        return ptrB;
      }

      ptrB = ptrB->next;
    }

    return nullptr;
  }
};

int main()
{
  ListNode *common = new ListNode(2, new ListNode(4));
  ListNode *nodeA = new ListNode(1, new ListNode(9, new ListNode(1, common)));
  ListNode *nodeB = new ListNode(3, common);

  Solution sol;
  ListNode *res = sol.getIntersectionNode(nodeA, nodeB);
  if (res)
  {
    printf("VAL: %d\n", res->val);
  }
  else
  {
    printf("not found\n");
  }
}
