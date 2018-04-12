class Solution {
 public:
  int maxArea(vector<int>& height) {
    vector<int> key(height);
    sort(key.rbegin(), key.rend());
    key.erase(unique(key.begin(), key.end()), key.end());

    unordered_map<int, int> mp;
    for (int i = 0; i < (int)key.size(); ++i) mp[key[i]] = i;

    vector<pair<int, int>> candidate(key.size(), pair<int, int>(-1, -1));
    for (int i = 0; i < (int)height.size(); ++i) {
      auto& now = candidate[mp[height[i]]];
      if (now.first == -1) now.first = i;
      now.second = i;
    }

    int ans = 0, l = height.size(), r = -1;
    for (int i = 0; i < (int)candidate.size(); ++i) {
      l = min(l, candidate[i].first), r = max(r, candidate[i].second);
      ans = max(ans, key[i] * (r - l));
    }
    return ans;
  }
};
