// Segment Tree {{{
template <typename T>
class SegmentTree {
 public:
  int n;
  vector<T> node;

  template <typename F>
  void Init(int now, int l, int r, F f) {
    if (l == r) {
      node[now] = f(l);
      return;
    }
    int mid = (l + r) >> 1;
    Init(now * 2, l, mid, f), Init(now * 2 + 1, mid + 1, r, f);
    node[now] = node[now * 2] + node[now * 2 + 1];
  }
  template <typename F>
  void Init(int _n, F f) {
    n = _n, node.resize(4 * (n + 1)), Init(1, 1, n, f);
  }
  void Init(int _n, T *a) {
    Init(_n, [a](int i) { return a[i]; });
  }
  void Init(int _n, vector<T> &a) {
    Init(_n, [&a](int i) { return a[i]; });
  }
  void Init(int _n, T val) {
    Init(_n, [val](int i) { return val; });
  }

  void Update(int now, int l, int r, int qx, T qv) {
    if (l == r) {
      node[now] = qv;
      return;
    }
    int mid = (l + r) >> 1;
    if (qx <= mid) Update(now * 2, l, mid, qx, qv);
    if (qx > mid) Update(now * 2 + 1, mid + 1, r, qx, qv);
    node[now] = node[now * 2] + node[now * 2 + 1];
  }
  void Update(int qx, T qv) {
    assert(1 <= qx and qx <= n);
    Update(1, 1, n, qx, qv);
  }

  T Query(int now, int l, int r, int ql, int qr) {
    if (ql <= l and r <= qr) return node[now];
    int mid = (l + r) >> 1;
    if (qr <= mid) return Query(now * 2, l, mid, ql, qr);
    if (ql > mid) return Query(now * 2 + 1, mid + 1, r, ql, qr);
    T tl = Query(now * 2, l, mid, ql, qr);
    T tr = Query(now * 2 + 1, mid + 1, r, ql, qr);
    return tl + tr;
  }
  T Query(int l, int r) {
    assert(l <= r);
    return Query(1, 1, n, l, r);
  }
};
// }}}

class Solution {
 public:
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people) {
    if (people.empty()) return vector<pair<int, int>>();
    int n = people.size();
    sort(people.begin(), people.end());
    people.insert(people.begin(), pair<int, int>(0, 0));

    SegmentTree<int> st;
    st.Init(n, 1);

    vector<pair<int, int>> ans(n, pair<int, int>(0, 0));
    vector<int> erase;
    for (int i = 1; i <= n; ++i) {
      int height = people[i].first;
      int pos = people[i].second;

      int l = 1, r = n, idx = 1;
      while (l <= r) {
        int mid = (l + r) >> 1;
        int now = st.Query(1, mid);
        if (now > (pos + 1)) {
          r = mid - 1;
        } else if (now == (pos + 1)) {
          idx = mid;
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      }

      ans[idx - 1] = {height, pos};
      erase.push_back(idx);
      if (i < n and height != people[i + 1].first) {
        for (auto &x : erase) st.Update(x, 0);
      }
    }
    return ans;
  }
};
