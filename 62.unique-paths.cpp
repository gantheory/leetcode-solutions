class Solution {
 public:
  const int N = 200;
  int uniquePaths(int m, int n) {
    --m, --n;
    int dp[N][N];
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) dp[i][j] = 0;

    for (int i = 0; i < N; ++i) dp[i][0] = dp[i][i] = 1;
    for (int i = 1; i < N; ++i)
      for (int j = 1; j < i; ++j) dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];

    return dp[m + n][m];
  }
};
