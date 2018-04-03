class Solution {
 public:
  int numSquares(int n) {
    vector<int> sq;
    int sn = floor(pow((double)n, 0.5));
    for (int i = 0; i <= sn; ++i) sq.push_back(i * i);

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int v : sq) {
        if (i - v < 0) break;
        dp[i] = min(dp[i], 1 + dp[i - v]);
      }
    }
    return dp[n];
  }
};
