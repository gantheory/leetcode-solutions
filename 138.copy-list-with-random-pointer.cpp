/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) return NULL;

    unordered_map<RandomListNode *, int> mp;
    RandomListNode *tmp = head;
    for (int i = 0; tmp != NULL; ++i, tmp = tmp->next) mp[&(*tmp)] = i;

    vector<RandomListNode *> v;
    tmp = head;
    while (tmp) {
      RandomListNode *now = new RandomListNode(tmp->label);
      v.push_back(now);
      tmp = tmp->next;
    }

    for (int i = 0; i + 1 < (int)v.size(); ++i) v[i]->next = v[i + 1];
    tmp = head;
    for (int i = 0; tmp != NULL; ++i, tmp = tmp->next)
      if (tmp->random) {
        int idx = mp[&(*tmp->random)];
        v[i]->random = v[idx];
      }
    return v[0];
  }
};
