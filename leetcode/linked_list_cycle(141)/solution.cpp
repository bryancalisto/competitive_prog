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
    unordered_set<ListNode *> set;

    if (!head)
    {
      return false;
    }

    while (head)
    {
      if (set.find(head) != set.end())
      {
        return true;
      }
      else
      {
        set.insert(head);
      }

      head = head->next;
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
  head->next->next->next->next = head->next;

  cout << sol.hasCycle(head);
}