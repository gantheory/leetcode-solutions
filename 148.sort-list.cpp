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
  void sort(ListNode* now, int size) {
    if (size <= 1) return;

    ListNode* nxt = now;
    for (int i = 0; i < size / 2; ++i) nxt = nxt->next;

    sort(now, size / 2);
    sort(nxt, size - size / 2);

    ListNode* head = now;
    vector<int> result;
    int i = 0, n = size / 2, j = 0, m = size - size / 2;
    while (i < n and j < m) {
      if (now->val < nxt->val) {
        result.push_back(now->val);
        ++i, now = now->next;
      } else {
        result.push_back(nxt->val);
        ++j, nxt = nxt->next;
      }
    }
    while (i < n) result.push_back(now->val), ++i, now = now->next;
    while (j < m) result.push_back(nxt->val), ++j, nxt = nxt->next;
    for (int i = 0; i < (int)result.size(); ++i) {
      head->val = result[i];
      head = head->next;
    }
  }
  ListNode* sortList(ListNode* head) {
    int size = 0;
    ListNode* tmp = head;
    while (tmp != NULL) ++size, tmp = tmp->next;
    sort(head, size);
    return head;
  }
};
