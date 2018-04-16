class Solution {
 public:
  vector<vector<bool>> visit;
  vector<vector<int>> ans;

  int dfs(int x, int y, vector<vector<int>>& matrix) {
    if (visit[x][y]) return ans[x][y];
    visit[x][y] = true;

    if (x > 0 and matrix[x][y] < matrix[x - 1][y])
      ans[x][y] = max(ans[x][y], 1 + dfs(x - 1, y, matrix));
    if (x + 1 < (int)matrix.size() and matrix[x][y] < matrix[x + 1][y])
      ans[x][y] = max(ans[x][y], 1 + dfs(x + 1, y, matrix));
    if (y > 0 and matrix[x][y] < matrix[x][y - 1])
      ans[x][y] = max(ans[x][y], 1 + dfs(x, y - 1, matrix));
    if (y + 1 < (int)matrix[x].size() and matrix[x][y] < matrix[x][y + 1])
      ans[x][y] = max(ans[x][y], 1 + dfs(x, y + 1, matrix));

    return ans[x][y];
  }

  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty() or matrix[0].empty()) return 0;

    visit.resize(matrix.size(), vector<bool>(matrix[0].size(), false));
    ans.resize(matrix.size(), vector<int>(matrix[0].size(), 1));

    for (int i = 0; i < (int)matrix.size(); ++i)
      for (int j = 0; j < (int)matrix[i].size(); ++j)
        if (!visit[i][j]) ans[i][j] = dfs(i, j, matrix);

    int mx = INT_MIN;
    for (int i = 0; i < (int)ans.size(); ++i)
      mx = max(mx, *max_element(ans[i].begin(), ans[i].end()));
    return mx;
  }
};
