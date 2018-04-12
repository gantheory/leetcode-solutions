class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    if (nums.size() == 0) return 0;
    vector<int> v;
    v.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
      int now = nums[i];
      if (now > v.back())
        v.push_back(now);
      else
        *lower_bound(v.begin(), v.end(), now) = now;
    }
    return v.size();
  }
};
