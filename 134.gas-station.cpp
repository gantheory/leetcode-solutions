class Solution {
 public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int total = 0, mn = INT_MAX, start = 0;
    for (int i = 0; i < (int)gas.size(); ++i) {
      total += gas[i] - cost[i];
      if (total < mn) mn = total, start = (i + 1) % gas.size();
    }
    return (total >= 0 ? start : -1);
  }
};
