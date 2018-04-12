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
  ListNode* reverseList(ListNode* head) {
    if (head == NULL or head->next == NULL) return head;
    ListNode* now = head->next;
    ListNode* prv = head;
    head->next = NULL;
    while (now) {
      ListNode* nxt = now->next;
      now->next = prv;
      prv = now;
      now = nxt;
    }
    return prv;
  }
};
