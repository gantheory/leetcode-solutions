class Solution {
 public:
  int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;
    if (nums.size() & 1) ans += nums.back();
    for (int i = 0; i < (int)nums.size(); i += 2)
      ans += min(nums[i], nums[i + 1]);
    return ans;
  }
};
