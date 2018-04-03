class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    map<int, vector<vector<int>>> mp;
    map<int, set<vector<int>>> checked;
    unordered_set<int> st(candidates.begin(), candidates.end());
    for (int i = 1; i <= target; ++i) {
      if (st.count(i)) {
        mp[i].push_back({i});
        checked[i].insert({i});
      }
      for (int value : candidates)
        if (mp.count(i - value)) {
          for (vector<int>& vc : mp[i - value]) {
            vector<int> now = {value};
            for (int j = 0; j < (int)vc.size(); ++j) now.push_back(vc[j]);
            sort(now.begin(), now.end());

            if (checked[i].count(now) == 0) {
              mp[i].push_back(now);
              checked[i].insert(now);
            }
          }
        }
    }
    return mp[target];
  }
};
