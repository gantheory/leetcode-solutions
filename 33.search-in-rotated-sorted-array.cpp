class Solution {
 public:
  int findPoint(vector<int>& nums) {
    if (!nums.size()) return -1;
    int l = 0, r = nums.size() - 1;

    if (nums[l] <= nums[r]) return 0;
    while (1) {
      if (r - l == 1) return r;
      int mid = (l + r) >> 1;
      if (nums[mid] > nums[l])
        l = mid;
      else
        r = mid;
    }
  }
  int search(vector<int>& nums, int target) {
    // search rotating point
    int rotatingPoint = findPoint(nums);
    if (rotatingPoint == -1) return -1;

    int l = 0, r = nums.size() - 1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int nowMid = (mid + rotatingPoint) % nums.size();
      if (nums[nowMid] < target)
        l = mid + 1;
      else if (nums[nowMid] > target)
        r = mid - 1;
      else
        return nowMid;
    }
    return -1;
  }
};
