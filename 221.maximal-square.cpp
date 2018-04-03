class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if ((int)matrix.size() == 0 or (int) matrix[0].size() == 0) return 0;
    vector<vector<int>> rowPS(matrix.size(), vector<int>(matrix[0].size(), 0));
    vector<vector<int>> colPS(matrix.size(), vector<int>(matrix[0].size(), 0));

    for (int i = 0; i < (int)matrix.size(); ++i) {
      rowPS[i][0] = matrix[i][0] - '0';
      for (int j = 1; j < (int)matrix[i].size(); ++j) {
        if (matrix[i][j] == '0') continue;
        rowPS[i][j] += rowPS[i][j - 1] + matrix[i][j] - '0';
      }
    }
    for (int j = 0; j < (int)matrix[0].size(); ++j) {
      colPS[0][j] = matrix[0][j] - '0';
      for (int i = 1; i < (int)matrix.size(); ++i) {
        if (matrix[i][j] == '0') continue;
        colPS[i][j] += colPS[i - 1][j] + matrix[i][j] - '0';
      }
    }

    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), 0));
    for (int i = 0; i < (int)matrix.size(); ++i)
      for (int j = 0; j < (int)matrix[i].size(); ++j) {
        dp[i][j] = matrix[i][j] - '0';
        if (i == 0 or j == 0 or matrix[i][j] == '0') continue;
        dp[i][j] = max(
            dp[i][j],
            1 + min(dp[i - 1][j - 1], min(rowPS[i][j - 1], colPS[i - 1][j])));
      }

    int ans = 0;
    for (int i = 0; i < (int)dp.size(); ++i)
      for (int j = 0; j < (int)dp[i].size(); ++j) ans = max(ans, dp[i][j]);
    return ans * ans;
  }
};
