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
  unordered_map<int, int> mp;
  int ans = 0;

  void dfs(TreeNode* v, int now, int sum) {
    if (v == NULL) return;
    now += v->val;
    ans += mp[now - sum];
    ++mp[now];
    dfs(v->left, now, sum);
    dfs(v->right, now, sum);
    --mp[now];
  }
  int pathSum(TreeNode* root, int sum) {
    mp[0] = 1;
    dfs(root, 0, sum);
    return ans;
  }
};
