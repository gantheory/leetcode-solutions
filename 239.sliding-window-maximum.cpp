class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.empty()) return vector<int>();

    deque<int> dq;
    for (int i = 0; i < k; ++i) {
      while (!dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
      dq.push_back(i);
    }

    vector<int> ans(1, nums[dq.front()]);
    for (int i = k; i < (int)nums.size(); ++i) {
      while (!dq.empty() and dq.front() <= i - k) dq.pop_front();
      while (!dq.empty() and nums[dq.back()] < nums[i]) dq.pop_back();
      dq.push_back(i);
      ans.push_back(nums[dq.front()]);
    }
    return ans;
  }
};
