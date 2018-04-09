class Solution {
 public:
  vector<vector<int>> ans;
  vector<int> path;

  void go(vector<vector<int>>& graph, int now) {
    path.push_back(now);
    if (now == (int)graph.size() - 1) {
      ans.push_back(path);
      path.pop_back();
      return;
    }

    for (auto& child : graph[now]) go(graph, child);
    path.pop_back();
  }
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    go(graph, 0);
    return ans;
  }
};
