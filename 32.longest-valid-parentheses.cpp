class Solution {
 public:
  int longestValidParentheses(string s) {
    s = "@" + s;
    vector<int> dp(s.size(), 0);

    for (int i = 2; i < (int)s.size(); ++i) {
      if (s[i] == '(') continue;
      if (s[i - 1] == '(') dp[i] = max(dp[i], dp[i - 2] + 2);
      int idx = i - dp[i - 1] - 1;
      if (s[idx] == '(') dp[i] = max(dp[i], dp[idx - 1] + 2 + dp[i - 1]);
    }
    return *max_element(dp.begin(), dp.end());
  }
};
