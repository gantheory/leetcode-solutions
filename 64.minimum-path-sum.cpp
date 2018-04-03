class Solution {
 public:
  const int INF = 1e9;
  int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), INF));
    dp[0][0] = grid[0][0];
    for (int num = 1; num <= (int)grid.size() - 1 + grid[0].size() - 1; ++num)
      for (int i = 0; i <= min(num, (int)grid.size() - 1); ++i) {
        int j = num - i;
        if (j >= (int)grid[0].size()) continue;
        if (i > 0) dp[i][j] = min(dp[i][j], dp[i - 1][j] + grid[i][j]);
        if (j > 0) dp[i][j] = min(dp[i][j], dp[i][j - 1] + grid[i][j]);
      }
    return dp.back().back();
  }
};
