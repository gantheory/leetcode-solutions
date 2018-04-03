/*!s and *
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
  bool equal(TreeNode* s, TreeNode* t) {
    if (!s and !t) return true;
    if (!s or !t) return false;
    return (s->val == t->val) and equal(s->left, t->left) and
           equal(s->right, t->right);
  }
  bool isSubtree(TreeNode* s, TreeNode* t) {
    if (equal(s, t)) return true;
    if (s and isSubtree(s->left, t)) return true;
    if (s and isSubtree(s->right, t)) return true;
    return false;
  }
};
