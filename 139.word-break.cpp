class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    vector<bool> dp(s.size(), false);
    for (int i = 0; i < (int)dp.size(); ++i) {
      for (string now : wordDict) {
        int idx = i - now.size() + 1;
        if (idx < 0 or (idx > 0 and !dp[idx - 1])) continue;
        bool fail = false;
        for (int j = 0; j < (int)now.size(); ++j)
          if (now[j] != s[idx + j]) {
            fail = true;
            break;
          }
        if (!fail) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp.back();
  }
};
