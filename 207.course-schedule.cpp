class Solution {
 public:
  bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(numCourses, vector<int>());
    vector<int> inDegree(numCourses, 0);

    for (auto pr : prerequisites) {
      int u = pr.second, v = pr.first;
      adj[u].push_back(v);
      ++inDegree[v];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (inDegree[i] == 0) q.push(i);
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      --numCourses;
      for (auto child : adj[now]) {
        --inDegree[child];
        if (inDegree[child] == 0) q.push(child);
      }
    }
    return (numCourses == 0);
  }
};
