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
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* now = &dummy;
    while (l1 and l2) {
      if (l1->val > l2->val) swap(l1, l2);
      now->next = l1;
      l1 = l1->next, now = now->next;
    }
    now->next = l1 ? l1 : l2;
    return dummy.next;
  }
};
