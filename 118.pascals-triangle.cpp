class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans = {{1}, {1, 1}};
    if (numRows == 0) return {};
    if (numRows == 1) return {{1}};
    for (int i = 0; i < numRows - 2; ++i) {
      vector<int> now(1, 1);
      for (int i = 0; i + 1 < (int)ans.back().size(); ++i)
        now.push_back(ans.back()[i] + ans.back()[i + 1]);
      now.push_back(1);
      ans.push_back(now);
    }
    return ans;
  }
};
