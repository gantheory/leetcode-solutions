class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<int> ans;

    vector<vector<int>> adj(numCourses, vector<int>());
    vector<int> in_degree(numCourses, 0);
    for (auto& p : prerequisites) {
      ++in_degree[p.first];
      adj[p.second].push_back(p.first);
    }

    vector<bool> visit(numCourses, false);
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
      if (in_degree[i] == 0) q.push(i), visit[i] = true;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      ans.push_back(now);
      for (int& child : adj[now]) {
        --in_degree[child];
        if (in_degree[child] == 0 and visit[child] == false)
          q.push(child), visit[child] = true;
      }
    }
    return ((int)ans.size() == numCourses ? ans : vector<int>());
  }
};
