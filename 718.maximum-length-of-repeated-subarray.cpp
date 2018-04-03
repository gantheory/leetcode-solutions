class Solution {
public:
  int findLength(vector<int> &A, vector<int> &B) {
    const int N = 1e3 + 10;

    int dp[N][N];
    for (int i = 0; i < (int)A.size(); ++i)
      for (int j = 0; j < (int)B.size(); ++j)
        dp[i][j] = 0;

    for (int i = 0; i < (int)A.size(); ++i)
      for (int j = 0; j < (int)B.size(); ++j)
        if (A[i] == B[j]) {
          dp[i][j] = 1;
          if (i != 0 and j != 0)
            dp[i][j] = dp[i - 1][j - 1] + 1;
        }

    int ans = -1;
    for (int i = 0; i < (int)A.size(); ++i)
      for (int j = 0; j < (int)B.size(); ++j)
        ans = max(ans, dp[i][j]);
    return ans;
  }
};
