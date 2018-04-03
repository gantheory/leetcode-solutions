class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if ((int)prices.size() <= 1) return 0;
    int mx = prices.back(), ans = 0;
    for (int i = prices.size() - 2; i >= 0; --i) {
      ans = max(ans, mx - prices[i]);
      mx = max(mx, prices[i]);
    }
    return ans;
  }
};
