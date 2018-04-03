class Solution {
 public:
  string decodeString(string s) {
    // find '[' and ']'
    size_t start = s.find_first_of('[');
    if (start == string::npos) return s;
    int now = 1, end = -1;
    for (int i = start + 1; i < (int)s.size(); ++i) {
      if (s[i] == '[')
        ++now;
      else if (s[i] == ']') {
        --now;
        if (now == 0) {
          end = i;
          break;
        }
      }
    }
    string ans;
    // prefix
    string prefix;
    for (int i = 0; i < (int)s.size(); ++i) {
      if ('0' <= s[i] and s[i] <= '9') break;
      prefix += s[i];
    }
    ans = prefix;
    // repeated part
    int repeatNum = stoi(s.substr(prefix.size(), start));
    string r = decodeString(s.substr(start + 1, end - start - 1));
    for (int i = 0; i < repeatNum; ++i) ans += r;
    // suffix
    string suffix = decodeString(s.substr(end + 1));
    ans += suffix;
    return ans;
  }
};
