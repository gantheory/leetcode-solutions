class Solution {
 public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> mp;
    for (int v : nums) ++mp[v];

    unordered_set<int> st;
    vector<pair<int, int>> sn(mp.size(), pair<int, int>());
    for (int v : nums) {
      if (st.count(v)) continue;
      sn[st.size()].first = mp[v], sn[st.size()].second = v;
      st.insert(v);
    }
    sort(sn.rbegin(), sn.rend());

    vector<int> ans(k, 0);
    for (int i = 0; i < k; ++i) ans[i] = sn[i].second;
    return ans;
  }
};
