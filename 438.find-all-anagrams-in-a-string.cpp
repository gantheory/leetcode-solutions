class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    if (s.size() < p.size()) return vector<int>();

    vector<int> target(26, 0);
    for (char c : p) ++target[c - 'a'];

    vector<int> now(26, 0), ans;
    for (int i = 0; i < (int)p.size(); ++i) ++now[s[i] - 'a'];
    if (target == now) ans.push_back(0);
    for (int i = p.size(); i < (int)s.size(); ++i) {
      --now[s[i - p.size()] - 'a'], ++now[s[i] - 'a'];
      if (target == now) ans.push_back(i - p.size() + 1);
    }
    return ans;
  }
};
