class Solution {
 public:
  int largestRectangleArea(vector<int>& heights) {
    vector<int> l(heights.size()), r(heights.size());
    iota(l.begin(), l.end(), 0), iota(r.begin(), r.end(), 0);

    stack<int> st;
    for (int i = 0; i < (int)heights.size(); ++i) {
      while (!st.empty() and heights[st.top()] > heights[i]) {
        r[st.top()] = i - 1;
        st.pop();
      }
      st.push(i);
    }
    while (!st.empty()) r[st.top()] = heights.size() - 1, st.pop();
    for (int i = heights.size() - 1; i >= 0; --i) {
      while (!st.empty() and heights[st.top()] > heights[i]) {
        l[st.top()] = i + 1;
        st.pop();
      }
      st.push(i);
    }
    while (!st.empty()) l[st.top()] = 0, st.pop();

    int ans = 0;
    for (int i = 0; i < (int)heights.size(); ++i)
      ans = max(ans, heights[i] * (r[i] - l[i] + 1));
    return ans;
  }
};
