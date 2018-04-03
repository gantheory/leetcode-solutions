class Solution {
 public:
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) return 0;
    vector<int> dp(amount + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= amount; ++i)
      for (int c : coins) {
        if (i - c < 0) continue;
        dp[i] = min(dp[i], 1 + dp[i - c]);
      }
    return (dp[amount] == 1e9 ? -1 : dp[amount]);
  }
};
