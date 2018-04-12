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
  ListNode* sort(ListNode* now, int size) {
    if (size == 0) return NULL;
    if (size == 1) return now;

    ListNode* nxt = now;
    ListNode* prv;
    for (int i = 0; i < size / 2; ++i) prv = nxt, nxt = nxt->next;
    prv->next = NULL;

    now = sort(now, size / 2);
    nxt = sort(nxt, size - size / 2);

    return mergeTwoLists(now, nxt);
  }
  ListNode* sortList(ListNode* head) {
    int size = 0;
    ListNode* tmp = head;
    while (tmp != NULL) ++size, tmp = tmp->next;
    head = sort(head, size);
    return head;
  }
};
