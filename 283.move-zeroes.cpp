class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    vector<int> nzIdx;
    for (int i = 0; i < (int)nums.size(); ++i)
      if (nums[i]) nzIdx.push_back(i);
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (i < (int)nzIdx.size())
        nums[i] = nums[nzIdx[i]];
      else
        nums[i] = 0;
    }
  }
};
