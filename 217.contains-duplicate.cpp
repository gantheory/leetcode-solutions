class Solution {
 public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for (int& v : nums) {
      if (s.count(v)) return true;
      s.insert(v);
    }
    return false;
  }
};
