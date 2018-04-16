class Solution {
 public:
  int firstUniqChar(string s) {
    unordered_set<char> s1, s2;
    for (char& c : s) {
      if (s1.count(c)) s2.insert(c);
      s1.insert(c);
    }
    for (int i = 0; i < (int)s.size(); ++i)
      if (s2.count(s[i]) == 0) return i;
    return -1;
  }
};
