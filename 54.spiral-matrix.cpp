class Solution {
 public:
  bool valid_x(int x, int dx, vector<vector<int>>& matrix) {
    return 0 <= x + dx and x + dx < (int)matrix.size();
  }

  bool valid_y(int y, int dy, vector<vector<int>>& matrix) {
    return 0 <= y + dy and y + dy < (int)matrix[0].size();
  }

  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> ans;
    if (matrix.empty() or matrix[0].empty()) return ans;
    vector<vector<bool>> visit(matrix.size(),
                               vector<bool>(matrix[0].size(), false));
    int x = 0, y = 0, dx = 0, dy = 1;
    while (ans.size() < matrix.size() * matrix[0].size()) {
      ans.push_back(matrix[x][y]);
      visit[x][y] = true;
      if (y + dy == (int)matrix[0].size() or
          (valid_y(y, dy, matrix) and visit[x][y + dy] and dy == 1)) {
        dx = 1, dy = 0;
      } else if (x + dx == (int)matrix.size() or
                 (valid_x(x, dx, matrix) and visit[x + dx][y] and dx == 1)) {
        dx = 0, dy = -1;
      } else if (y + dy == -1 or
                 (valid_y(y, dy, matrix) and visit[x][y + dy] and dy == -1)) {
        dx = -1, dy = 0;
      } else if (x + dx == -1 or
                 (valid_x(x, dx, matrix) and visit[x + dx][y] and dx == -1)) {
        dx = 0, dy = 1;
      }
      x += dx, y += dy;
    }
    return ans;
  }
};
