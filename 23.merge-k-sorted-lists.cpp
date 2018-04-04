/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
template <class T>
using MinHeap = priority_queue<T, vector<T>, greater<T>>;
class Solution {
 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    vector<ListNode*> now;
    for (int i = 0; i < (int)lists.size(); ++i)
      if (lists[i]) now.push_back(lists[i]);
    if (now.empty()) return NULL;

    MinHeap<pair<int, int>> heap;
    for (int i = 0; i < (int)now.size(); ++i) heap.push({now[i]->val, i});

    vector<int> result;
    int numOfDone = 0;
    while (numOfDone < (int)now.size()) {
      int value = heap.top().first;
      int i = heap.top().second;
      heap.pop();
      result.push_back(value);
      if (now[i]->next) {
        now[i] = now[i]->next;
        heap.push({now[i]->val, i});
      } else {
        ++numOfDone;
      }
    }

    ListNode* head = new ListNode(result[0]);
    ListNode* go = head;
    for (int i = 1; i < (int)result.size(); ++i) {
      go->next = new ListNode(result[i]);
      go = go->next;
    }
    return head;
  }
};
