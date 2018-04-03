class Solution {
 public:
  void sortColors(vector<int>& nums) {
    int count[3];
    fill(count, count + 3, 0);
    for (int a : nums) ++count[a];
    for (int i = 0; i < (int)nums.size(); ++i) {
      if (i < count[0])
        nums[i] = 0;
      else if (i < count[0] + count[1])
        nums[i] = 1;
      else
        nums[i] = 2;
    }
  }
};
