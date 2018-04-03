class Solution {
public:
  int countSubstrings(string s) {
    int ans = 0;

    string ss = "@";
    for (int i = 0; i < (int)s.size(); ++i)
      ss += s[i], ss += "@";

    for (int i = 0; i < (int)ss.size(); ++i) {
      int l = 0;
      while (i - l >= 0 and i + l < (int)ss.size() and ss[i - l] == ss[i + l])
        ++l;
      --l;

      ans += l / 2;
      if (ss[i] != '@')
        ++ans;
    }

    return ans;
  }
};
