class Solution {
 public:
  string a, b;

  bool equal(char a, char b) {
    if (a == '.' or b == '.') return true;
    return a == b;
  }

  bool myMatch(int ia, int ib) {
    if (ib >= (int)b.size()) return (ia >= (int)a.size());

    if ((b.size() - ib) >= 2 and b[ib + 1] == '*')
      return (myMatch(ia, ib + 2) or
              ((ia < (int)a.size()) and equal(a[ia], b[ib]) and
               myMatch(ia + 1, ib)));
    else
      return ((ia < (int)a.size()) and equal(a[ia], b[ib]) and
              myMatch(ia + 1, ib + 1));
  }

  bool isMatch(string s, string p) {
    a = s, b = p;
    return myMatch(0, 0);
  }
};
