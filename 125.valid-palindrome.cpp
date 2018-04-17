class Solution {
 public:
  bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    string now;
    for (char& c : s)
      if (isdigit(c) or isalpha(c)) now += c;
    for (int i = 0; i < (int)now.size(); ++i)
      if (now[i] != now[now.size() - 1 - i]) return false;
    return true;
  }
};
