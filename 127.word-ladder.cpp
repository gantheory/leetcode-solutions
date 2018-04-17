class Solution {
 public:
  bool close(string& a, string& b) {
    int diff = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
      if (a[i] != b[i]) ++diff;
      if (diff > 1) return false;
    }
    return true;
  }
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int target = -1;
    for (int i = 0; i < (int)wordList.size(); ++i)
      if (wordList[i] == endWord) {
        target = i + 1;
        break;
      }
    if (target == -1) return 0;

    vector<vector<int>> adj(wordList.size() + 1, vector<int>());
    for (int i = 0; i < (int)wordList.size(); ++i)
      if (close(beginWord, wordList[i]))
        adj[0].push_back(i + 1), adj[i + 1].push_back(0);
    for (int i = 0; i < (int)wordList.size(); ++i)
      for (int j = i + 1; j < (int)wordList.size(); ++j)
        if (close(wordList[i], wordList[j]))
          adj[i + 1].push_back(j + 1), adj[j + 1].push_back(i + 1);

    vector<bool> visit(wordList.size() + 1, false);
    queue<pair<int, int>> q;
    q.push({0, 1});
    while (!q.empty()) {
      int now = q.front().first;
      int step = q.front().second;
      q.pop();

      if (now == target) return step;
      if (visit[now]) continue;
      visit[now] = true;

      for (int& child : adj[now]) q.push({child, step + 1});
    }
    return 0;
  }
};
