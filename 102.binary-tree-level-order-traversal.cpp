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
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
      TreeNode* now = q.front().first;
      int level = q.front().second;
      q.pop();
      if (now == NULL) continue;

      while (level >= (int)ans.size()) ans.push_back(vector<int>());
      ans[level].push_back(now->val);
      q.push({now->left, level + 1}), q.push({now->right, level + 1});
    }
    return ans;
  }
};
