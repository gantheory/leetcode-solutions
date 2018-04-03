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
  bool go(TreeNode* now, long long l, long long r) {
    if (now == NULL) return true;
    if (now->val < l or now->val > r) return false;

    return go(now->left, l, (long long)now->val - 1) &&
           go(now->right, (long long)now->val + 1, r);
  }
  bool isValidBST(TreeNode* root) { return go(root, LLONG_MIN, LLONG_MAX); }
};
