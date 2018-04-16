/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
 public:
  unordered_map<TreeNode*, int> mp;
  int cal(TreeNode* now) {
    if (now == NULL) return 0;
    return mp[now] = 1 + cal(now->left) + cal(now->right);
  }
  int go(TreeNode* root, int k) {
    assert(root != NULL);
    int rank = mp[root->left] + 1;
    if (rank < k)
      return go(root->right, k - rank);
    else if (rank == k)
      return root->val;
    else
      return go(root->left, k);
  }
  int kthSmallest(TreeNode* root, int k) {
    mp[NULL] = 0, cal(root);
    return go(root, k);
  }
};
