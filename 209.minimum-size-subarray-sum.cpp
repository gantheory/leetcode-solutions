class Solution {
public:
  int minSubArrayLen(int s, vector<int> &nums) {
    int ans = nums.size() + 1;

    vector<int> ps = {0};
    for (int i = 0; i < (int)nums.size(); ++i)
      ps.push_back(ps.back() + nums[i]);

    for (int i = 1; i < (int)ps.size(); ++i) {
      int l = 0, r = i - 1, mid;
      while (l <= r) {
        mid = (l + r) >> 1;
        if (ps[i] - ps[mid] >= s)
          l = mid + 1, ans = min(ans, i - mid);
        else
          r = mid - 1;
      }
    }

    return (ans == nums.size() + 1 ? 0 : ans);
  }
};
