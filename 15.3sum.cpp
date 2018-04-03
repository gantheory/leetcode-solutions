class Solution {
public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> ans;
    if ((int)nums.size() < 3)
      return ans;

    sort(nums.begin(), nums.end());
    vector<int> indices = {0};
    for (int i = 1; i < (int)nums.size(); ++i)
      if (nums[i - 1] != nums[i])
        indices.push_back(i);

    for (int i : indices) {
      int end = nums.size() - 1;
      for (int j = i + 1; j < end; ++j) {
        int target = -(nums[i] + nums[j]);

        if (target > nums[end])
          continue;
        while (end > j and nums[end] > target)
          --end;
        if (end > j and nums[end] == target)
          ans.push_back({nums[i], nums[j], target});

        while (nums[end] == target)
          --end;
      }
    }

    return ans;
  }
};
