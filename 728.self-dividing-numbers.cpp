class Solution {
 public:
  bool check(int now) {
    int tmp = now;
    while (tmp) {
      int checkNum = tmp % 10;
      tmp /= 10;
      if (checkNum == 0 or (now % checkNum)) return false;
    }
    return true;
  }
  vector<int> selfDividingNumbers(int left, int right) {
    vector<int> ans;
    for (int i = left; i <= right; ++i)
      if (check(i)) ans.push_back(i);
    return ans;
  }
};
