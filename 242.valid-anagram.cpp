class Solutio {
 public:
  void cal(string& s, vector<int>& now) {
    for (char& c : s) ++now[c];
  }
  bool isAnagram(string s, string t) {
    vector<int> ss(128, 0), tt(128, 0);
    cal(s, ss), cal(t, tt);
    return ss == tt;
  }
};
