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
  int diameter = 0;
  unordered_map<TreeNode*, int> mp;

  int setR(TreeNode* now) {
    if (!now) return 0;
    if (!now->left and !now->right) {
      mp[now] = 0;
      return 0;
    }
    int left = setR(now->left);
    int right = setR(now->right);
    mp[now] = 1 + max(left, right);
    diameter = max(diameter, mp[now]);
    return mp[now];
  }
  void go(TreeNode* now) {
    if (now and now->left and now->right)
      diameter = max(diameter, mp[now->left] + mp[now->right] + 2);
    if (now) go(now->left), go(now->right);
  }
  int diameterOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    mp[NULL] = 0, setR(root);
    go(root);
    return diameter;
  }
};
