class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    long long n = nums.size();
    return n * (n + 1) / 2 - accumulate(nums.begin(), nums.end(), (long long)0);
  }
};
