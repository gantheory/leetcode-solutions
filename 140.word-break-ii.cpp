class Solution {
 public:
  void go(int now, vector<vector<string>>& dp, vector<vector<int>>& prv,
          vector<string>& nowAns, vector<string>& ans) {
    if (now == -1) {
      string tmp = nowAns.back();
      for (int i = nowAns.size() - 2; i >= 0; --i) tmp += " " + nowAns[i];
      ans.push_back(tmp);
      return;
    }

    for (int i = 0; i < (int)dp[now].size(); ++i) {
      nowAns.push_back(dp[now][i]);
      go(prv[now][i], dp, prv, nowAns, ans);
      nowAns.pop_back();
    }
  }
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    vector<vector<string>> dp(s.size(), vector<string>());
    vector<vector<int>> prv(s.size(), vector<int>());
    for (int i = 0; i < (int)s.size(); ++i)
      for (string& t : wordDict) {
        if (t.size() > i + 1 or
            (i - t.size() != -1 and dp[i - t.size()].empty()))
          continue;
        bool is_match = true;
        for (int j = 0; j < (int)t.size(); ++j)
          if (t[j] != s[i - t.size() + 1 + j]) {
            is_match = false;
            break;
          }
        if (is_match) {
          dp[i].push_back(t);
          prv[i].push_back(i - t.size());
        }
      }

    vector<string> ans;
    vector<string> nowAns;
    go(s.size() - 1, dp, prv, nowAns, ans);
    return ans;
  }
};
