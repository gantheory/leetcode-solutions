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
  void add(stack<TreeNode*>& st, TreeNode* now) {
    if (now == NULL) return;
    if (now->right) st.push(now->right);
    st.push(now);
    if (now->left) st.push(now->left);
    now->left = now->right = NULL;
  }
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* now = root;
    add(st, now);
    while (!st.empty()) {
      TreeNode* now = st.top();
      st.pop();
      if (now->right == NULL and now->left == NULL) {
        ans.push_back(now->val);
        continue;
      }
      add(st, now);
    }
    return ans;
  }
};
