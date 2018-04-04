class Solution {
 public:
  vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
    if (buildings.empty()) return vector<pair<int, int>>();

    vector<int> pos;
    for (int i = 0; i < (int)buildings.size(); ++i)
      pos.insert(pos.end(), buildings[i].begin(), buildings[i].begin() + 2);
    sort(pos.begin(), pos.end());
    pos.resize(unique(pos.begin(), pos.end()) - pos.begin());

    unordered_map<int, int> hash;
    for (int i = 0; i < (int)pos.size(); ++i) hash[pos[i]] = i;

    vector<vector<int>> flag(pos.size(), vector<int>());
    for (int i = 0; i < (int)buildings.size(); ++i) {
      int nowL = hash[buildings[i][0]], nowR = hash[buildings[i][1]];
      flag[nowL].push_back(i), flag[nowR].push_back(i);
    }

    vector<int> height(pos.size(), 0);
    unordered_set<int> checked;
    map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < (int)height.size(); ++i) {
      for (int idx : flag[i]) {
        int nowHeight = buildings[idx][2];
        if (checked.count(idx)) {
          --mp[nowHeight];
          if (mp[nowHeight] == 0) mp.erase(nowHeight);
          checked.erase(idx);
        } else {
          ++mp[nowHeight];
          checked.insert(idx);
        }
      }
      height[i] = mp.rbegin()->first;
    }

    vector<pair<int, int>> ans;
    int prvHeight = -1;
    for (int i = 0; i + 1 < (int)height.size(); ++i) {
      int nowPos = pos[i];
      int nowHeight = height[i];
      if (nowHeight != prvHeight) {
        ans.push_back({nowPos, nowHeight});
        prvHeight = nowHeight;
      }
    }
    ans.push_back({pos.back(), 0});
    return ans;
  }
};
