class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    if (matrix.empty() or matrix[0].empty()) return;
    vector<bool> row(matrix.size(), false), col(matrix[0].size(), false);
    for (int i = 0; i < (int)matrix.size(); ++i)
      for (int j = 0; j < (int)matrix[i].size(); ++j)
        if (matrix[i][j] == 0) row[i] = col[j] = true;
    for (int i = 0; i < (int)matrix.size(); ++i)
      for (int j = 0; j < (int)matrix[i].size(); ++j)
        if (row[i] or col[j]) matrix[i][j] = 0;
  }
};
