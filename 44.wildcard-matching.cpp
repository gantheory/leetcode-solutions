class Solution {
 public:
  bool equal(char a, char b) { return (a == b or a == '?' or b == '?'); }

  bool isMatch(string s, string p) {
    int is = 0, ip = 0, prvStar = -1, tmp_s = -1;
    while (is < (int)s.size()) {
      if (equal(s[is], p[ip])) {
        ++is, ++ip;
        continue;
      } else if (ip < (int)p.size() and p[ip] == '*') {
        prvStar = ip;
        tmp_s = is;
        ++ip;
        continue;
      } else if (prvStar != -1) {
        ip = prvStar + 1;
        is = tmp_s + 1;
        ++tmp_s;
        continue;
      }
      return false;
    }
    while (ip < (int)p.size() and p[ip] == '*') ++ip;
    return ip == (int)p.size();
  }
};
