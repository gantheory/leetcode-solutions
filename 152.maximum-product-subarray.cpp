class Solution {
public:
  int maxProduct(vector<int> &nums) {
    int ans = INT_MIN;
    vector<int> dp[2] = {{nums[0]}, {nums[0]}};
    for (int i = 1; i < (int)nums.size(); ++i) {
      int pp = (nums[i] > 0 ? 0 : 1);
      int np = (nums[i] > 0 ? 1 : 0);
      dp[0].push_back(max(dp[pp][i - 1] * nums[i], nums[i]));
      dp[1].push_back(min(dp[np][i - 1] * nums[i], nums[i]));
    }
    return *max_element(dp[0].begin(), dp[0].end());
  }
};
