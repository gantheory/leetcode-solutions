class Solution {
public:
  int longestPalindromeSubseq(string s) {
    vector<vector<int>> dp;
    vector<int> _;
    dp.push_back(_);

    for (int i = 1; i <= (int)s.size(); ++i) {
      vector<int> now;
      if (i == 1) {
        for (int j = 0; j < (int)s.size(); ++j)
          now.push_back(1);
      } else {
        for (int j = 0; j + i - 1 < (int)s.size(); ++j) {
          now.push_back(max(dp[i - 1][j], dp[i - 1][j + 1]));
          if (s[j] == s[j + i - 1]) {
            if (i > 2)
              now.back() = max(now.back(), dp[i - 2][j + 1] + 2);
            else
              now.back() += 1;
          }
        }
      }
      dp.push_back(now);
    }

    return dp.back()[0];
  }
};
