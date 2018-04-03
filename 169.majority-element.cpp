class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto& v : nums) {
      ++mp[v];
      if (mp[v] > (int)nums.size() / 2) return v;
    }
  }
};
