class Solution {
 public:
  vector<int> findAnagrams(string s, string p) {
    vector<int> target(26, 0);
    for (char c : p) ++target[c - 'a'];

    vector<vector<int>> source(s.size() + 1, vector<int>(26, 0));
    for (int i = 0; i < (int)s.size(); ++i) ++source[i + 1][s[i] - 'a'];
    for (int i = 1; i < (int)source.size(); ++i)
      for (int j = 0; j < 26; ++j) source[i][j] += source[i - 1][j];

    vector<int> ans;
    for (int i = 1; i + p.size() - 1 < (int)source.size(); ++i) {
      bool valid = true;
      for (int j = 0; j < 26; ++j)
        if (target[j] != source[i + p.size() - 1][j] - source[i - 1][j]) {
          valid = false;
          break;
        }
      if (valid) ans.push_back(i - 1);
    }
    return ans;
  }
};
