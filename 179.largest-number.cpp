class Solution {
 public:
  static bool compare(string& a, string& b) {
    for (int i = 0; i < (int)a.size() + b.size(); ++i) {
      char ca = (i >= (int)a.size() ? b[i - a.size()] : a[i]);
      char cb = (i >= (int)b.size() ? a[i - b.size()] : b[i]);
      if (ca != cb) return ca > cb;
    }
    return a.size() < b.size();
  }
  string largestNumber(vector<int>& nums) {
    vector<string> now;
    for (int& v : nums) now.push_back(to_string(v));
    sort(now.begin(), now.end(), compare);
    string ans;
    for (string& s : now) ans += s;
    int idx = 0;
    for (int i = 0; i < (int)ans.size(); ++i) {
      if (ans[i] != '0') break;
      idx = i + 1;
    }
    if (idx == (int)ans.size()) return "0";
    return ans.substr(idx);
  }
};
