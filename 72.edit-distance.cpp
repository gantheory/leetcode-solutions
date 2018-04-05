class Solution {
 public:
  int minDistance(string word1, string word2) {
    word1 = "@" + word1, word2 = "@" + word2;

    vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), 0));
    for (int i = 0; i < (int)word1.size(); ++i) dp[i][0] = i;
    for (int j = 0; j < (int)word2.size(); ++j) dp[0][j] = j;
    for (int i = 1; i < (int)word1.size(); ++i)
      for (int j = 1; j < (int)word2.size(); ++j) {
        dp[i][j] = dp[i - 1][j - 1] + (word1[i] != word2[j]);
        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
      }
    return dp.back().back();
  }
};
