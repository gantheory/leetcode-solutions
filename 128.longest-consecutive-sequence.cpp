class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> mp, rmp;
    int ans = 0;
    for (auto& v : nums) {
      if (mp[v]) continue;
      int left = mp[v - 1], right = mp[v + 1], now = left + right + 1;
      mp[v] = mp[v - left] = mp[v + right] = now;
      ans = max(ans, now);
    }
    return ans;
  }
};
