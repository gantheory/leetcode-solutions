class Solution {
public:
  string longestPalindrome(string s) {
    array<int, 2500> ans;
    ans.fill(0);

    string ss = "_";
    for (auto c : s)
      ss += c, ss += "_";

    for (int i = 0; i < (int)ss.size(); ++i) {
      int l = 0;
      while (i - l >= 0 and i + l < (int)ss.size() and ss[i - l] == ss[i + l])
        ++l;
      --l;
      ans[i] = 2 * l + 1;
    }

    auto it = max_element(ans.begin(), ans.end());
    int idx = it - ans.begin(), len = *it;
    string as = "";
    for (int i = idx - len / 2; i <= idx + len / 2; ++i)
      if (ss[i] != '_')
        as += ss[i];
    return as;
  }
};
