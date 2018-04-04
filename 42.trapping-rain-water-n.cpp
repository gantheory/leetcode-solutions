class Solution {
 public:
  int trap(vector<int>& height) {
    int ans = 0;
    int l = 0, r = height.size() - 1, maxL = 0, maxR = 0;
    while (l <= r) {
      if (height[l] <= height[r]) {
        maxL = max(maxL, height[l]);
        ans += maxL - height[l];
        ++l;
      } else {
        maxR = max(maxR, height[r]);
        ans += maxR - height[r];
        --r;
      }
    }
    return ans;
  }
};
