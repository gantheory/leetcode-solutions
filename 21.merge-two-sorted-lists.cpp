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
    if (!l1) return l2;
    if (!l2) return l1;
    if (l1->val > l2->val) swap(l1, l2);
    ListNode* ans = l1;
    ListNode* prv = l1;
    l1 = l1->next;
    while (l1 and l2) {
      if (l1->val > l2->val) {
        ListNode* l2Next = l2->next;
        prv->next = l2;
        l2->next = l1;
        l2 = l2Next;
        prv = prv->next;
      } else {
        prv = l1;
        l1 = l1->next;
      }
    }
    if (l2) {
      ListNode* tmp = ans;
      while (tmp->next) tmp = tmp->next;
      tmp->next = l2;
    }
    return ans;
  }
};
