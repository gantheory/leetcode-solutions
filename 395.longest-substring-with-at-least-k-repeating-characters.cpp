class Solution {
 public:
  int longestSubstring(string& s, int l, int r, int k) {
    if (s.empty()) return 0;

    vector<int> count(26, 0);
    for (int i = l; i <= r; ++i) ++count[s[i] - 'a'];

    bool findAns = true;
    for (int i = 0; i < 26; ++i)
      if (0 < count[i] and count[i] < k) {
        findAns = false;
        break;
      }
    if (findAns) return r - l + 1;

    int ans = 0, prv = l - 1;
    for (int i = l; i <= r; ++i)
      if (0 < count[s[i] - 'a'] and count[s[i] - 'a'] < k) {
        ans = max(ans, longestSubstring(s, prv + 1, i - 1, k));
        prv = i;
      }
    ans = max(ans, longestSubstring(s, prv + 1, r, k));
    return ans;
  }
  int longestSubstring(string s, int k) {
    return longestSubstring(s, 0, s.size() - 1, k);
  }
};
