class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() or matrix[0].empty()) return false;
    int i = 0, j = matrix[0].size() - 1;
    while (0 <= i and i < (int)matrix.size() and 0 <= j and
           j < (int)matrix[0].size()) {
      if (matrix[i][j] == target) return true;
      if (target < matrix[i][j])
        --j;
      else
        ++i;
    }
    return false;
  }
};
