class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    int idx = 0;
    for (int i = 0; i < (int)nums.size(); ++i)
      if (nums[i]) nums[idx++] = nums[i];
    fill(nums.begin() + idx, nums.end(), 0);
  }
};
