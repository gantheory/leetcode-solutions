class Solution {
 public:
  int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < (int)nums.size(); ++i)
      if (nums[i] == nums[i - 1]) return nums[i];
  }
};
