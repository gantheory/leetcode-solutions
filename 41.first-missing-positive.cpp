class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < (int)nums.size(); ++i) nums[i] = max(nums[i], 0);
    for (int i = 0; i < (int)nums.size(); ++i) {
      int now = abs(nums[i]);
      if (now == 0 or now > (int)nums.size()) continue;
      if (nums[now - 1] == 0)
        nums[now - 1] = -now;
      else
        nums[now - 1] = -abs(nums[now - 1]);
    }
    for (int i = 0; i < (int)nums.size(); ++i)
      if (nums[i] >= 0) return i + 1;
    return nums.size() + 1;
  }
};
