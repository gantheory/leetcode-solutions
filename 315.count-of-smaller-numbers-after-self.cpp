#define mid ((l + r) >> 1)
class Node {
 public:
  int value, l, r;
  Node() {}
  Node(int _v) : value(_v) { l = r = 0; }
};
class SegmentTree {
 public:
  static const int L = INT_MIN;
  static const int R = INT_MAX;
  vector<Node> st;

  inline void Pull(int now) {
    int lchild = st[now].l;
    int rchild = st[now].r;
    st[now].value = st[lchild].value + st[rchild].value;
  }
  void Build() {
    st.push_back(Node(0));  // Null Node
    st.push_back(Node(0));
  }
  void Update(int q, int now = 1, int l = L, int r = R) {
    if (q < l or q > r) return;
    if (l == q and q == r) {
      ++st[now].value;
      return;
    }
    if (q <= mid) {
      if (st[now].l == 0) {
        st[now].l = st.size();
        st.push_back(Node(0));
      }
      Update(q, st[now].l, l, mid);
    } else {
      if (st[now].r == 0) {
        st[now].r = st.size();
        st.push_back(Node(0));
      }
      Update(q, st[now].r, mid + 1, r);
    }
    Pull(now);
  }
  int Query(int ql, int qr, int now = 1, int l = L, int r = R) {
    if (ql > qr or qr < l or ql > r) return 0;
    if (l == ql && qr == r) {
      return st[now].value;
    }
    if (qr <= mid) {
      if (st[now].l == 0) return 0;
      return Query(ql, qr, st[now].l, l, mid);
    } else if (mid < ql) {
      if (st[now].r == 0) return 0;
      return Query(ql, qr, st[now].r, mid + 1, r);
    } else {
      int lchild = Query(ql, mid, st[now].l, l, mid);
      int rchild = Query(mid + 1, qr, st[now].r, mid + 1, r);
      return lchild + rchild;
    }
  }
};
class Solution {
 public:
  vector<int> countSmaller(vector<int>& nums) {
    if (nums.empty()) return vector<int>();
    reverse(nums.begin(), nums.end());
    SegmentTree st;
    st.Build();
    vector<int> ans;
    for (int i = 0; i < (int)nums.size(); ++i) {
      ans.push_back(st.Query(INT_MIN, nums[i] - 1));
      st.Update(nums[i]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
