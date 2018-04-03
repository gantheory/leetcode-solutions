class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    // transpose
    int n = matrix.size();
    for (int i = 0; i < n; ++i)
      for (int j = i + 1; j < n; ++j) swap(matrix[i][j], matrix[j][i]);
    // reverse each row
    for (auto& v : matrix) reverse(v.begin(), v.end());
  }
};
