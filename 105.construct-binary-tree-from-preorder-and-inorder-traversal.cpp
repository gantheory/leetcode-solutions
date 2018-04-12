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
  TreeNode* buildTree(int lp, int rp, int li, int ri, vector<int>& preorder,
                      vector<int>& inorder) {
    if (lp > rp or li > ri) return NULL;
    TreeNode* ans = new TreeNode(preorder[lp]);
    int idx = -1;
    for (int i = li; i <= ri; ++i)
      if (inorder[i] == preorder[lp]) {
        idx = i;
        break;
      }
    int len = idx - li;
    ans->left =
        buildTree(lp + 1, lp + len, li, li + len - 1, preorder, inorder);
    ans->right =
        buildTree(lp + len + 1, rp, li + len + 1, ri, preorder, inorder);
    return ans;
  }
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTree(0, preorder.size() - 1, 0, inorder.size() - 1, preorder,
                     inorder);
  }
};
