class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    int l = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (l == (int)nums.size() or nums[l] != target) return vector<int>(2, -1);
    int r = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
    return {l, r};
  }
};
