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
  bool equal(TreeNode* a, TreeNode* b) {
    if (!a and b) return false;
    if (a and !b) return false;
    if (!a and !b) return true;
    if (a->val != b->val) return false;
    return equal(a->left, b->right) && equal(a->right, b->left);
  }
  bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return equal(root->left, root->right);
  }
};
