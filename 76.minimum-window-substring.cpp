class Solution {
 public:
  string minWindow(string s, string t) {
    if (t.empty()) return "";

    vector<int> count(128, 0);
    for (char& c : t) ++count[c];

    vector<int> now(count.size(), 0);
    int num = 0;
    for (int i = 0; i < (int)now.size(); ++i)
      if (now[i] >= count[i]) ++num;

    string ans = "";
    int end = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (i > 0) {
        --now[s[i - 1]];
        if (now[s[i - 1]] < count[s[i - 1]]) --num;
      }
      while (end < (int)s.size() and num < (int)now.size()) {
        ++now[s[end]];
        if (now[s[end]] == count[s[end]]) ++num;
        ++end;
      }
      if (num == (int)now.size() and
          ((end - i) < (int)ans.size() or ans.empty()))
        ans = s.substr(i, end - i);
    }
    return ans;
  }
};
