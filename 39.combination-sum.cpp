class Solution {
 public:
  vector<vector<int>> ans;
  vector<int> combination;
  void go(int now, vector<int>& candidates, int target) {
    if (target == 0) {
      ans.push_back(combination);
      return;
    }
    for (int i = now; i < (int)candidates.size(); ++i) {
      if (target - candidates[i] < 0) break;
      combination.push_back(candidates[i]);
      go(i, candidates, target - candidates[i]);
      combination.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    ans.clear(), combination.clear();
    sort(candidates.begin(), candidates.end());
    go(0, candidates, target);
    return ans;
  }
};
