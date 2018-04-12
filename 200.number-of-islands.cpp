// Disjoint Set {{{
class DisjointSet {
 public:
  vector<int> p, sz;

  DisjointSet() {}
  DisjointSet(int x) { Init(x); }
  void Init(int x) {
    ++x, p.resize(x), sz.resize(x, 1), iota(p.begin(), p.end(), 0);
  }
  int Find(int x) { return x == p[x] ? x : p[x] = Find(p[x]); }
  void Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    p[x] = y, sz[y] += sz[x];
  }
  bool IsSame(int x, int y) { return Find(x) == Find(y); }
  bool IsRoot(int x) { return x == p[x]; }
};
// }}}
class Solution {
 public:
  int n;

  int hash(int x, int y) { return x * n + y; }

  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty() or grid[0].empty()) return 0;

    DisjointSet st(grid.size() * grid[0].size());
    n = grid[0].size();

    for (int i = 0; i < (int)grid.size(); ++i)
      for (int j = 0; j < (int)grid[i].size(); ++j) {
        if (grid[i][j] == '0') continue;

        if (i > 0 and grid[i - 1][j] == '1')
          st.Union(hash(i, j), hash(i - 1, j));
        if (i + 1 < (int)grid.size() and grid[i + 1][j] == '1')
          st.Union(hash(i, j), hash(i + 1, j));
        if (j > 0 and grid[i][j - 1] == '1')
          st.Union(hash(i, j), hash(i, j - 1));
        if (j + 1 < (int)grid[i].size() and grid[i][j + 1] == '1')
          st.Union(hash(i, j), hash(i, j + 1));
      }

    int ans = 0;
    for (int i = 0; i < (int)grid.size(); ++i)
      for (int j = 0; j < (int)grid[i].size(); ++j)
        if (grid[i][j] == '1' and st.IsRoot(hash(i, j))) ++ans;
    return ans;
  }
};
