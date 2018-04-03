class Solution {
public:
  string longestPalindrome(string s) {
    string ss = "_";
    for (auto c : s)
      ss += c, ss += "_";

    array<int, 2500> ans;
    ans.fill(0);

    int l = 0, r = 0;
    ans[0] = 1;
    for (int i = 1; i < (int)ss.size(); ++i) {
      if (i > r) {
        l = r = i;
        while (l > 0 and r < (int)ss.size() - 1 and ss[l - 1] == ss[r + 1])
          --l, ++r;
        ans[i] = r - l + 1;
      } else {
        int md = (l + r) / 2, j = md + md - i;
        ans[i] = ans[j];
        int q = ans[i] / 2, nr = i + q;
        if (nr == r) {
          l = i + i - r;
          while (l > 0 and r < (int)ss.size() - 1 and ss[l - 1] == ss[r + 1])
            --l, ++r;
          ans[i] = r - l + 1;
        } else if (nr > r)
          ans[i] = (r - i) * 2 + 1;
      }
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
