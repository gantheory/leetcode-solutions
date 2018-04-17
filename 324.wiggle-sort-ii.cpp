class Solution {
 public:
  void remove(int now, map<int, int>& mp) {
    --mp[now];
    if (mp[now] == 0) mp.erase(now);
  }
  void wiggleSort(vector<int>& nums) {
    map<int, int> mp;
    for (int& v : nums) ++mp[v];

    for (int i = 0; i < (int)nums.size(); i += 2) {
      nums[i] = mp.begin()->first;
      remove(nums[i], mp);
      nums[i + 1] = (++mp.begin())->first;
      remove(nums[i + 1], mp);
    }
    if (mp.size() == 1) nums.back() = mp.begin()->first;
  }
};
