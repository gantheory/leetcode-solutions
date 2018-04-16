class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    int mn1 = INT_MAX, mn2 = INT_MAX;
    for (int& v : nums) {
      if (v <= mn1)
        mn1 = v;
      else if (v <= mn2)
        mn2 = v;
      else
        return true;
    }
    return false;
  }
};
