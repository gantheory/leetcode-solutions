class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> ans;

    int st = 0, ed = numbers.size() - 1;
    while (st <= ed) {
      int now = numbers[st] + numbers[ed];
      if (now == target) {
        ans.push_back(st + 1);
        ans.push_back(ed + 1);
        break;
      }
      if (now < target)
        ++st;
      else
        --ed;
    }
    return ans;
  }
};
