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
  ListNode* reverse(int len, ListNode* head) {
    if (len <= 1) return head;
    ListNode* now = head->next;
    ListNode* prv = head;
    for (int i = 1; i < len; ++i) {
      ListNode* nxt = now->next;
      now->next = prv;
      prv = now, now = nxt;
    }
    head->next = now;
    return prv;
  }
  bool isPalindrome(ListNode* head) {
    if (head == NULL) return true;
    int len = 0;
    ListNode* tmp = head;
    while (tmp) ++len, tmp = tmp->next;
    head = reverse(len / 2, head);
    tmp = head;
    for (int i = 0; i < len / 2; ++i) tmp = tmp->next;
    if (len & 1) tmp = tmp->next;
    for (int i = 0; i < len / 2; ++i) {
      if (head->val != tmp->val) return false;
      head = head->next, tmp = tmp->next;
    }
    return true;
  }
};
