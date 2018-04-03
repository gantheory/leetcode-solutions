class Solution {
public:
  void sum(vector<int> &nums, int target, int start, int n,
           vector<vector<int>> &ans) {
    if (start == (int)nums.size())
      return;

    if (n == 1) {
      auto it = lower_bound(nums.begin() + start, nums.end(), target);
      if (it != nums.end() and *it == target)
        ans.push_back({target});
      return;
    }

    vector<int> indices = {start};
    for (int i = start + 1; i < (int)nums.size(); ++i)
      if (nums[i - 1] != nums[i])
        indices.push_back(i);

    for (int i : indices) {
      int st_size = ans.size();
      sum(nums, target - nums[i], i + 1, n - 1, ans);
      for (int j = st_size; j < (int)ans.size(); ++j)
        ans[j].push_back(nums[i]);
    }
  }

  vector<vector<int>> fourSum(vector<int> &nums, int target) {
    vector<vector<int>> ans;
    if ((int)nums.size() < 4)
      return ans;
    sort(nums.begin(), nums.end());
    sum(nums, target, 0, 4, ans);
    return ans;
  }
};
