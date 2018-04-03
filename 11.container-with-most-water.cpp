class Solution {
 public:
  int maxArea(vector<int>& height) {
    vector<int> key(height);
    sort(key.begin(), key.end());
    key.erase(unique(key.begin(), key.end()), key.end());

    vector<vector<int>> candidate(key.size(), vector<int>());
    for (int i = 0; i < (int)height.size(); ++i) {
      int idx = lower_bound(key.begin(), key.end(), height[i]) - key.begin();
      candidate[idx].push_back(i);
    }

    int ans = 0, l = height.size(), r = -1;
    for (int i = candidate.size() - 1; i >= 0; --i) {
      int nowL = candidate[i][0];
      int nowR = candidate[i].back();
      int nowHeight = key[i];
      l = min(nowL, l);
      r = max(nowR, r);
      ans = max(ans, (r - l) * nowHeight);
    }
    return ans;
  }
};
