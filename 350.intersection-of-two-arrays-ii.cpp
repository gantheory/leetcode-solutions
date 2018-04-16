class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> st;
    unordered_map<int, int> mp1, mp2;
    for (int& v : nums1) ++mp1[v], st.insert(v);
    for (int& v : nums2) ++mp2[v];

    vector<int> ans;
    for (auto& v : st)
      if (mp1.count(v) and mp2.count(v))
        ans.insert(ans.end(), min(mp1[v], mp2[v]), v);
    return ans;
  }
};
