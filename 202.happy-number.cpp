class Solution {
 public:
  unordered_set<int> st;

  bool go(int n) {
    if (st.count(n)) return false;
    if (n == 1) return true;
    st.insert(n);
    int now = 0;
    while (n) {
      int tmp = n % 10;
      now += tmp * tmp;
      n /= 10;
    }
    return go(now);
  }

  bool isHappy(int n) {
    st.clear();
    return go(n);
  }
};
