class Solution {
 public:
  int calculate(string s) {
    istringstream ss("+" + s + "+");
    int ans = 0, now = 0;
    char op;
    while (ss >> op) {
      int tmp;
      ss >> tmp;
      if (op == '+')
        ans += now, now = tmp;
      else if (op == '-')
        ans += now, now = -tmp;
      else if (op == '*')
        now *= tmp;
      else
        now /= tmp;
    }
    return ans;
  }
};
