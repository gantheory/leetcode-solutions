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
  ListNode* oddEvenList(ListNode* head) {
    if (head == NULL) return NULL;

    ListNode* tail = head;
    while (tail->next) tail = tail->next;

    ListNode* tmp = head;
    int len = 0;
    while (tmp) tmp = tmp->next, ++len;
    if (len <= 2) return head;

    ListNode* prv = head;
    ListNode* now = head;
    for (int i = 0; i < len; ++i) {
      if (i & 1) {
        ListNode* nxt = now->next;
        prv->next = now->next;
        tail->next = now;
        now->next = NULL;
        tail = tail->next;
        prv = prv->next;
        now = nxt;
      } else {
        prv = now;
        now = now->next;
      }
    }
    return head;
  }
};
