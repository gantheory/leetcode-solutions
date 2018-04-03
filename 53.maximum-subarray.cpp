class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ans = nums[0], now = 0;
    for (auto& v : nums) {
      now += v;
      ans = max(ans, now);
      now = max(now, 0);
    }
    return ans;
  }
};
