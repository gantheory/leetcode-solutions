class Solution {
 public:
  vector<vector<string>> ans;
  vector<string> now;

  bool is_palindrome(string& s) {
    for (int i = 0; i < (int)s.size() / 2; ++i)
      if (s[i] != s[s.size() - 1 - i]) return false;
    return true;
  }
  void go(int idx, string& s) {
    if (idx == (int)s.size()) {
      ans.push_back(now);
      return;
    }
    for (int i = idx; i < (int)s.size(); ++i) {
      string now_s = s.substr(idx, i - idx + 1);
      if (is_palindrome(now_s)) {
        now.push_back(now_s);
        go(i + 1, s);
        now.pop_back();
      }
    }
  }
  vector<vector<string>> partition(string s) {
    ans.clear();
    go(0, s);
    return ans;
  }
};
