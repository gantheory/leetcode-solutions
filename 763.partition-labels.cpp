class Solution {
 public:
  vector<int> partitionLabels(string S) {
    vector<pair<int, int>> v(26, pair<int, int>(-1, -1));
    for (int i = 0; i < (int)S.size(); ++i) {
      if (v[S[i] - 'a'].first == -1) v[S[i] - 'a'].first = i;
      v[S[i] - 'a'].second = i;
    }

    vector<int> line(S.size(), 0);
    for (int i = 0; i < 26; ++i) {
      if (v[i].first == -1) continue;
      ++line[v[i].first], --line[v[i].second];
    }

    vector<int> ans;
    int now = 0, prv = -1;
    for (int i = 0; i < (int)line.size(); ++i) {
      now += line[i];
      if (now == 0) ans.push_back(i - prv), prv = i;
    }
    return ans;
  }
};
