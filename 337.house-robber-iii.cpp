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
  int rob(TreeNode* root) {
    if (root == NULL) return 0;

    int rootV = root->val;
    int leftV = (root->left ? rob(root->left) : 0);
    int rightV = (root->right ? rob(root->right) : 0);

    if (root->left) {
      rootV += (root->left->left ? rob(root->left->left) : 0);
      rootV += (root->left->right ? rob(root->left->right) : 0);
    }
    if (root->right) {
      rootV += (root->right->left ? rob(root->right->left) : 0);
      rootV += (root->right->right ? rob(root->right->right) : 0);
    }

    return max(rootV, leftV + rightV);
  }
};
