#include <bits/stdc++.h>
#include <unordered_set>
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
  bool hasCycle(ListNode *head)
  {
    if (!head)
    {
      return false;
    }

    /* Based on the turtle hare algorithm*/
    ListNode *oneStep = head;
    ListNode *twoStep = head;

    while (twoStep && twoStep->next)
    {
      oneStep = oneStep->next;
      twoStep = twoStep->next->next;

      if (oneStep == twoStep)
      {
        return true;
      }
    }

    return false;
  }
};

int main()
{
  Solution sol;
  ListNode *head = &ListNode(3);
  head->next = &ListNode(2);
  head->next->next = &ListNode(0);
  head->next->next->next = &ListNode(4);
  // head->next->next->next->next = head->next;

  cout << sol.hasCycle(head);
}