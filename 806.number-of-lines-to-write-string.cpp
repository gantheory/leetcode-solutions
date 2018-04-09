class Solution {
 public:
  vector<int> numberOfLines(vector<int>& widths, string S) {
    vector<int> ans(2, 0);
    for (char& c : S) {
      ans[1] += widths[c - 'a'];
      if (ans[1] > 100) ++ans[0], ans[1] = widths[c - 'a'];
    }
    ++ans[0];
    return ans;
  }
};
