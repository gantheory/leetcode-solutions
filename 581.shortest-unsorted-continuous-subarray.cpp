class Solution {
 public:
  int findUnsortedSubarray(vector<int>& nums) {
    vector<int> tmp(nums.begin(), nums.end());
    sort(tmp.begin(), tmp.end());
    int start = -1, end = -1;
    for (int i = 0; i < (int)nums.size(); ++i)
      if (nums[i] != tmp[i]) {
        if (start == -1) start = i;
        end = i;
      }
    if (start == -1 and end == -1) return 0;
    return end - start + 1;
  }
};
