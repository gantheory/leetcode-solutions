class Solution {
 public:
  bool canJump(vector<int>& nums) {
    vector<bool> go(nums.size(), false);
    go.back() = true;
    int mn = nums.size() - 1;
    for (int i = nums.size() - 2; i >= 0; --i)
      if (i + nums[i] >= mn) {
        go[i] = true;
        mn = i;
      }
    return go[0];
  }
};
