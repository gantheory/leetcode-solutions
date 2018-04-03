class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    int ans = 0;

    vector<int> ps = {nums[0]};
    for (int i = 1; i < (int)nums.size(); ++i)
      ps.push_back(ps.back() + nums[i]);

    map<int, int> mp;
    mp[0] = 1;
    for (int i = 0; i < (int)ps.size(); ++i) {
      ans += mp[ps[i] - k];
      ++mp[ps[i]];
    }

    return ans;
  }
};
