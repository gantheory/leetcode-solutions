class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) return 0;
    vector<int> buy(prices.size(), 0), sell(prices.size(), 0);
    buy[0] = -prices[0];
    for (int i = 1; i < (int)prices.size(); ++i) {
      buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i]);
    }
    return sell.back();
  }
};
