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
    if (l > r) return NULL;
    if (l == r) {
      TreeNode* ans = new TreeNode(nums[l]);
      return ans;
    }

    int mid = (l + r) >> 1;
    TreeNode* now = new TreeNode(nums[mid]);
    now->left = go(nums, l, mid - 1);
    now->right = go(nums, mid + 1, r);
    return now;
  }
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    return go(nums, 0, nums.size() - 1);
  }
};
