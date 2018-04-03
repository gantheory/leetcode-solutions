class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    vector<string> s = {"",    "",    "abc",  "def", "ghi",
                        "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans[2];

    int now = 0, prv = 1;
    for (int i = 0; i < (int)digits.size(); ++i) {
      now ^= 1, prv ^= 1;
      int idx = digits[i] - '0';

      if (i == 0) {
        for (int j = 0; j < (int)s[idx].size(); ++j)
          ans[now].push_back(string(s[idx], j, 1));
      } else {
        ans[now].clear();
        for (int j = 0; j < (int)s[idx].size(); ++j)
          for (auto nows : ans[prv]) ans[now].push_back(nows + s[idx][j]);
      }
    }
    return ans[now];
  }
};
