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
  vector<vector<int>> ans;
  void go(TreeNode* now, int depth) {
    if (now == NULL) return;
    if (depth == (int)ans.size()) ans.push_back(vector<int>());
    ans[depth].push_back(now->val);
    go(now->left, depth + 1), go(now->right, depth + 1);
  }
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    ans.clear();
    go(root, 0);
    for (int i = 1; i < (int)ans.size(); i += 2)
      reverse(ans[i].begin(), ans[i].end());
    return ans;
  }
};
