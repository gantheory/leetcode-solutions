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
  int ans = INT_MIN;

  int cal(TreeNode* now) {
    if (now == NULL) return 0;
    int left = cal(now->left), right = cal(now->right);
    ans = max(ans, now->val);
    ans = max(ans, max(left, right) + now->val);
    ans = max(ans, left + right + now->val);
    return max(now->val, max(left, right) + now->val);
  }
  int maxPathSum(TreeNode* root) {
    cal(root);
    return ans;
  }
};
