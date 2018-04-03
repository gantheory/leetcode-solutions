class Solution {
public:
  int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C,
                   vector<int> &D) {
    int ans = 0;

    map<int, int> all;
    for (int a : A)
      for (int b : B)
        ++all[a + b];

    for (int c : C)
      for (int d : D)
        if (all.count(-(c + d)))
          ans += all[-(c + d)];

    return ans;
  }
};
