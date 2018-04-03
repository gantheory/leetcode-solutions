class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    prices.insert(prices.begin(), 0);
    vector<int> buy(prices.size(), 0);
    vector<int> sell(prices.size(), 0);

    buy[1] = -prices[1];
    for (int i = 2; i < (int)prices.size(); ++i) {
      buy[i] = max(sell[i - 2] - prices[i], buy[i - 1]);
      sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
    }
    return sell.back();
  }
};
