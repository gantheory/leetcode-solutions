class Solution {
 public:
  int leastInterval(vector<char>& tasks, int n) {
    vector<int> count(26, 0);
    for (char c : tasks) ++count[c - 'A'];
    int mx = *max_element(count.begin(), count.end());
    int num = 0;
    for (auto& v : count)
      if (v == mx) ++num;
    int period = n + 1;
    return max((int)tasks.size(), (mx - 1) * period + num);
  }
};
