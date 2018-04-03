class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int S) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum < S) return 0;
    sum += S;
    if (sum & 1) return 0;

    sum >>= 1;
    sum = abs(sum);
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int v : nums)
      for (int i = sum; i >= v; --i) dp[i] += dp[i - v];
    return dp[sum];
  }
};
