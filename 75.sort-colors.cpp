class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int c[3] = {0, 0, 0};
    for (int a : nums) ++c[a];
    fill(nums.begin(), nums.begin() + c[0], 0);
    fill(nums.begin() + c[0], nums.begin() + c[0] + c[1], 1);
    fill(nums.begin() + c[0] + c[1], nums.begin() + c[0] + c[1] + c[2], 2);
  }
};
