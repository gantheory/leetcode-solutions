class Solution {
 public:
  int open, close, len;
  string nowAns;
  unordered_set<string> hash;
  vector<string> ans;

  void go(int now, string& s) {
    if (open < close or open > len or close > len) return;
    if (now == (int)s.size()) {
      if (open == len and close == len and hash.count(nowAns) == 0)
        ans.push_back(nowAns), hash.insert(nowAns);
      return;
    }

    if (s[now] == '(') {
      go(now + 1, s);

      ++open, nowAns.push_back(s[now]);
      go(now + 1, s);
      --open, nowAns.pop_back();
    } else if (s[now] == ')') {
      go(now + 1, s);

      ++close, nowAns.push_back(s[now]);
      go(now + 1, s);
      --close, nowAns.pop_back();
    } else {
      nowAns.push_back(s[now]);
      go(now + 1, s);
      nowAns.pop_back();
    }
  }

  vector<string> removeInvalidParentheses(string s) {
    open = close = len = 0;
    stack<int> st;
    for (int i = 0; i < (int)s.size(); ++i) {
      if (s[i] == '(') {
        st.push(s[i]);
      } else if (s[i] == ')') {
        if (!st.empty() and st.top() == '(') st.pop(), ++len;
      }
    }

    nowAns = "", go(0, s);
    return ans;
  }
};
