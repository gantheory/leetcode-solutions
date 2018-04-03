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
    ListNode* tmp = head;
    vector<int> result;
    while (tmp) result.push_back(tmp->val), tmp = tmp->next;

    tmp = head;
    while (tmp) tmp->val = result.back(), result.pop_back(), tmp = tmp->next;
    return head;
  }
};
