class Solution {
 public:
  vector<int> getAfterHeight(vector<int>& height) {
    vector<int> r(height.size(), 0);
    iota(r.begin(), r.end(), 0);

    stack<pair<int, int>> st;
    st.push({height[0], 0});
    for (int i = 1; i < (int)height.size(); ++i) {
      while (!st.empty() and st.top().first <= height[i]) {
        r[st.top().second] = i;
        st.pop();
      }
      st.push({height[i], i});
    }
    vector<vector<int>> flags(height.size(), vector<int>());
    for (int i = 0; i < (int)r.size(); ++i)
      flags[i].push_back(i), flags[r[i]].push_back(i);

    unordered_set<int> checked;
    map<int, int> mp;
    vector<int> after(height.begin(), height.end());
    for (int i = 0; i < (int)after.size(); ++i) {
      for (auto& idx : flags[i]) {
        if (checked.count(idx)) {
          checked.erase(idx);
          --mp[height[idx]];
          if (mp[height[idx]] == 0) mp.erase(height[idx]);
        } else {
          checked.insert(idx);
          ++mp[height[idx]];
        }
      }
      if (!mp.empty()) after[i] = max(after[i], mp.rbegin()->first);
    }
    return after;
  }
  int trap(vector<int>& height) {
    if (height.empty()) return 0;

    vector<int> rHeight(height.begin(), height.end());
    reverse(rHeight.begin(), rHeight.end());
    vector<int> rAfter = getAfterHeight(rHeight);
    reverse(rAfter.begin(), rAfter.end());

    vector<int> after = getAfterHeight(height);

    int ans = 0;
    for (int i = 0; i < (int)after.size(); ++i)
      ans += max(after[i], rAfter[i]) - height[i];
    return ans;
  }
};
