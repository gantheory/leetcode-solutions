class MinStack {
 public:
  map<int, int> mp;
  stack<int> st;
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) { ++mp[x], st.push(x); }

  void pop() {
    --mp[st.top()];
    if (mp[st.top()] == 0) mp.erase(st.top());
    st.pop();
  }

  int top() { return st.top(); }

  int getMin() { return mp.begin()->first; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
