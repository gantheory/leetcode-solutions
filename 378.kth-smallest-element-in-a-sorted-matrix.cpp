class Solution {
 public:
  long long cal(vector<vector<int>>& matrix, long long target) {
    long long now = 0;
    for (int i = 0; i < (int)matrix.size(); ++i)
      now += upper_bound(matrix[i].begin(), matrix[i].end(), target) -
             matrix[i].begin();
    return now;
  }
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    long long l = matrix[0][0], r = matrix.back().back(), ans;
    while (l <= r) {
      long long mid = (l + r) >> 1;
      long long now = cal(matrix, mid);
      if (now >= k)
        ans = mid, r = mid - 1;
      else
        l = mid + 1;
    }
    return ans;
  }
};
