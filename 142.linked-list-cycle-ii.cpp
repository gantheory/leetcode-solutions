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
  ListNode *detectCycle(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (slow and fast) {
      if (fast->next == NULL) return NULL;
      slow = slow->next, fast = fast->next->next;
      if (slow == fast) break;
    }
    if (fast == NULL) return NULL;

    fast = head;
    while (slow != fast) slow = slow->next, fast = fast->next;
    return fast;
  }
};
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
  ListNode *detectCycle(ListNode *head) {
    set<ListNode *> st;
    while (head != NULL) {
      if (st.count(head)) return head;
      st.insert(head);
      head = head->next;
    }
    return NULL;
  }
};
