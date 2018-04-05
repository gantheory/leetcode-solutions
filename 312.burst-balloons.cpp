class Solution {
 public:
  vector<vector<int>> mp;

  int go(int l, int r, vector<int>& nums) {
    if (l > r) return mp[l][r] = 0;

    if (l == r) return (mp[l][l] = nums[l - 1] * nums[l] * nums[l + 1]);
    if (mp[l][r] == INT_MIN) {
      for (int i = l; i <= r; ++i)
        mp[l][r] = max(mp[l][r], nums[l - 1] * nums[i] * nums[r + 1] +
                                     go(l, i - 1, nums) + go(i + 1, r, nums));
    }
    return mp[l][r];
  }

  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    nums.insert(nums.begin(), 1), nums.push_back(1);
    mp.resize(nums.size(), vector<int>(nums.size(), INT_MIN));
    return go(1, n, nums);
  }
};
