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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *ans = l1;
    while (1) {
      if (!l1 and !l2)
        break;

      if (l2)
        l1->val += l2->val;
      if (l1->val > 9) {
        if (!l1->next)
          l1->next = new ListNode(0);
        l1->next->val += 1;
        l1->val -= 10;
      }

      if (!l1->next and l2 and l2->next)
        l1->next = new ListNode(0);
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
    }
    return ans;
  }
};
