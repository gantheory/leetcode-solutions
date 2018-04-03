class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    int ans = accumulate(nums.begin(), nums.begin() + 3, 0);

    sort(nums.begin(), nums.end());
    vector<int> indices = {0};
    for (int i = 1; i < (int)nums.size(); ++i)
      if (nums[i - 1] != nums[i])
        indices.push_back(i);

    for (int i : indices) {
      int start = i + 1, end = nums.size() - 1;
      while (start < end) {
        int now = nums[i] + nums[start] + nums[end];
        if (abs(now - target) < abs(ans - target))
          ans = now;
        if (now < target)
          ++start;
        else
          --end;
      }
    }

    return ans;
  }
};
