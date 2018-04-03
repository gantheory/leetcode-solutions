class Solution {
public:
  int numSubarrayProductLessThanK(vector<int> &nums, int k) {
    int s = nums[0], r = 0, ans = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (i > r) {
        r = i;
        s = nums[i];
      }

      while (r + 1 < (int)nums.size() and s * nums[r + 1] < k)
        s *= nums[r + 1], ++r;
      if (s < k)
        ans += r - i + 1;

      s /= nums[i];
    }
    return ans;
  }
};
