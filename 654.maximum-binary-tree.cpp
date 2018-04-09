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
  TreeNode* go(vector<int>& nums, int l, int r) {
    if (nums.empty() or l > r) return NULL;
    int idx =
        max_element(nums.begin() + l, nums.begin() + r + 1) - nums.begin();
    TreeNode* ans = new TreeNode(nums[idx]);
    ans->left = go(nums, l, idx - 1), ans->right = go(nums, idx + 1, r);
    return ans;
  }
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    return go(nums, 0, nums.size() - 1);
  }
};
