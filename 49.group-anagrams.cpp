class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    vector<vector<string>> ans;
    unordered_map<string, int> mp;
    for (string s : strs) {
      string tmpS = s;
      sort(tmpS.begin(), tmpS.end());
      if (mp.count(tmpS)) {
        ans[mp[tmpS]].push_back(s);
      } else {
        mp[tmpS] = ans.size();
        ans.push_back({s});
      }
    }
    return ans;
  }
};
