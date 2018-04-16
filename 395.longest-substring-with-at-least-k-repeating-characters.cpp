class Solution {
 public:
  int longestSubstring(string s, int k) {
    if (s.empty()) return 0;
    vector<int> count(26, 0);
    int prv = 0, st = 0, ans = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      int now = s[i] - 'a';
      ++count[now];
      if (count[now] == 1)
        ++st;
      else if (count[now] == k)
        --st;
      if (st == 0) ans = max(ans, i - prv);
    }
  }
};
