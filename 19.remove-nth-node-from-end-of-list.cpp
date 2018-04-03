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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    int len = 0;
    ListNode* go = head;
    while (go) {
      go = go->next;
      ++len;
    }
    if (len == 1) return NULL;

    int nth = len - n + 1;
    if (nth == 1) return head->next;
    ListNode* prv = NULL;
    ListNode* now = head;
    for (int i = 0; i < nth - 1; ++i) {
      prv = now;
      now = now->next;
    }
    prv->next = now->next;
    return head;
  }
};
