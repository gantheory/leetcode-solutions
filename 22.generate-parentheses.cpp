class Solution {
 public:
  string s;
  vector<string> ans;
  int open = 0, close = 0;

  void go(int now) {
    if (now == (int)s.size()) {
      ans.push_back(s);
      return;
    }
    if (open < (int)s.size() / 2) {
      ++open;
      s[now] = '(';
      go(now + 1);
      --open;
    }
    if (open > close) {
      ++close;
      s[now] = ')';
      go(now + 1);
      --close;
    }
  }
  vector<string> generateParenthesis(int n) {
    for (int i = 0; i < 2 * n; ++i) s += "@";
    go(0);
    return ans;
  }
};
