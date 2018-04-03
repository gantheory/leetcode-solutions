class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    if (!s.size())
      return 0;

    int st = 0, ed = 1, ans = 1;
    map<char, int> mp;
    mp[s[0]] = 0;
    while (ed < (int)s.size()) {
      if (mp.count(s[ed])) {
        int idx = mp[s[ed]] + 1;
        for (int i = st; i < idx; ++i)
          mp.erase(s[i]);
        st = idx;
      }
      mp[s[ed]] = ed;
      ans = max(ans, ed - st + 1);
      ++ed;
    }

    return ans;
  }
};
