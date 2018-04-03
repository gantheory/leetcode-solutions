class Solution {
 public:
  vector<vector<int>> ans;
  vector<bool> choose;

  void go(int now, vector<int>& nums) {
    if (now == (int)nums.size()) {
      vector<int> nowAns;
      for (int i = 0; i < (int)nums.size(); ++i)
        if (choose[i]) nowAns.push_back(nums[i]);
      ans.push_back(nowAns);
      return;
    }

    choose[now] = false;
    go(now + 1, nums);
    choose[now] = true;
    go(now + 1, nums);
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    choose.resize(nums.size());
    go(0, nums);
    return ans;
  }
};
