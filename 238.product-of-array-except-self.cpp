class Solution {
public:
  vector<int> productExceptSelf(vector<int> &nums) {
    vector<int> ans(nums.size(), 1);

    int s = 1;
    for (int i = 0; i < (int)nums.size(); ++i)
      ans[i] *= s, s *= nums[i];

    s = 1;
    for (int i = nums.size() - 1; i >= 0; --i)
      ans[i] *= s, s *= nums[i];

    return ans;
  }
};
