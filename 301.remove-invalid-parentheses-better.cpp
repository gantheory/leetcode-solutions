class Solution {
 public:
  vector<string> ans;
  void go(string s, int ii, int jj, string par) {
    int st = 0;
    for (int i = ii; i < (int)s.size(); ++i) {
      if (s[i] == par[0]) ++st;
      if (s[i] == par[1]) --st;
      if (st >= 0) continue;
      for (int j = jj; j <= i; ++j)
        if (s[j] == par[1] and (j == jj or s[j - 1] != par[1]))
          go(s.substr(0, j) + s.substr(j + 1), i, j, par);
      return;
    }
    reverse(s.begin(), s.end());
    if (par[0] == '(')
      go(s, 0, 0, ")(");
    else
      ans.push_back(s);
  }
  vector<string> removeInvalidParentheses(string s) {
    ans.clear();
    go(s, 0, 0, "()");
    return ans;
  }
};
