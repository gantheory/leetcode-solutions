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
  bool isPalindrome(ListNode* head) {
    vector<int> result;
    ListNode* tmp = head;
    while (tmp) result.push_back(tmp->val), tmp = tmp->next;
    reverse(result.begin(), result.end());
    for (int i = 0; i < (int)result.size(); ++i, head = head->next)
      if (head->val != result[i]) return false;
    return true;
  }
};
