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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if ((int)preorder.size() == 0) return NULL;
    TreeNode* ans = new TreeNode(preorder[0]);
    int len = -1;
    for (int i = 0; i < (int)inorder.size(); ++i)
      if (inorder[i] == preorder[0]) {
        len = i;
        break;
      }

    vector<int> lp(preorder.begin() + 1, preorder.begin() + 1 + len);
    vector<int> li(inorder.begin(), inorder.begin() + len);
    ans->left = buildTree(lp, li);

    if (len < (int)preorder.size()) {
      vector<int> rp(preorder.begin() + len + 1, preorder.end());
      vector<int> ri(inorder.begin() + len + 1, inorder.end());
      ans->right = buildTree(rp, ri);
    }
    return ans;
  }
};
