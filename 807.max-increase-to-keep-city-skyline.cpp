class Solution {
 public:
  int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
    if (grid.empty() or grid[0].empty()) return 0;
    vector<vector<int>> height(grid.size(), vector<int>(grid[0].size(), 0));
    for (int i = 0; i < (int)grid.size(); ++i) {
      int mx = *max_element(grid[i].begin(), grid[i].end());
      fill(height[i].begin(), height[i].end(), mx);
    }

    for (int j = 0; j < (int)grid[0].size(); ++j) {
      int mx = INT_MIN;
      for (int i = 0; i < (int)grid.size(); ++i)
        if (grid[i][j] > mx) mx = grid[i][j];

      for (int i = 0; i < (int)height.size(); ++i)
        height[i][j] = min(height[i][j], mx);
    }

    int ans = 0;
    for (int i = 0; i < (int)grid.size(); ++i)
      for (int j = 0; j < (int)grid[i].size(); ++j)
        ans += height[i][j] - grid[i][j];
    return ans;
  }
};
