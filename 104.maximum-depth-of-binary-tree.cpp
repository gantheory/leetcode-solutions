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
  int ans = 0;
  void go(TreeNode* root, int now) {
    if (root == NULL) return;
    ans = max(ans, now);
    go(root->left, now + 1);
    go(root->right, now + 1);
  }
  int maxDepth(TreeNode* root) {
    go(root, 1);
    return ans;
  }
};
