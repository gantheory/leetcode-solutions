/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA;
    ListNode *b = headB;
    bool flagA = false, flagB = false;
    while (a and b) {
      if (a == b) return a;
      a = a->next, b = b->next;
      if (!a and !flagA) a = headB, flagA = true;
      if (!b and !flagB) b = headA, flagB = true;
    }
    return NULL;
  }
};
