//https://leetcode.com/problems/add-two-numbers/
#include <bits/stdc++.h>

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

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
  ListNode *res = new ListNode();
  ListNode *root = res;
  int carry = 0;

  while (l1 || l2)
  {
    if (l1 && l2)
    {
      printf("%d + %d  + %d= %d\n", l1->val, l2->val, carry, l1->val + l2->val + carry);
      res->val = l1->val + l2->val + carry;
      l1 = l1->next;
      l2 = l2->next;
    }
    else if (l1)
    {
      printf("%d + %d= %d\n", l1->val, carry, l1->val + carry);
      res->val = l1->val + carry;
      l1 = l1->next;
    }
    else if (l2)
    {
      printf("%d + %d= %d\n", l2->val, carry, l2->val + carry);
      res->val = l2->val + carry;
      l2 = l2->next;
    }

    if (res->val > 9)
    {
      res->val %= 10;
      // printf("carry => %d\n", res->val);
      carry = 1;
    }
    else
    {
      carry = 0;
    }
    if (l1 || l2)
    {
      res->next = new ListNode();
      res = res->next;
    }
  }

  if (carry)
  {
    res->next = new ListNode(1);
  }

  while (root)
  {
    printf("val = %d\n", root->val);
    root = root->next;
  }

  return root;
}

int main()
{
  ListNode *res;
  ListNode *ll1 = new ListNode(9);
  ListNode *ll2 = new ListNode(9);
  ListNode *ll3 = new ListNode(9);
  ListNode *ll4 = new ListNode(9);
  ListNode *ll5 = new ListNode(9);
  ListNode *ll6 = new ListNode(9);
  ListNode *ll7 = new ListNode(9);

  ll1->next = ll2;
  ll2->next = ll3;
  ll3->next = ll4;
  ll4->next = ll5;
  ll5->next = ll6;
  ll6->next = ll7;

  ListNode *ll4a = new ListNode(9);
  ListNode *ll5a = new ListNode(9);
  ListNode *ll6a = new ListNode(9);
  ListNode *ll7a = new ListNode(9);

  ll4a->next = ll5a;
  ll5a->next = ll6a;
  ll6a->next = ll7a;

  res = addTwoNumbers(ll1, ll4);

  delete ll1;
  delete ll2;
  delete ll3;
  delete ll4;
  delete ll5;
  delete ll6;
  delete res;
}