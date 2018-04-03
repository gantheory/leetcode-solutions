class Solution {
 public:
  static bool compare(pair<int, int>& a, pair<int, int>& b) {
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
  }
  vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
    sort(people.begin(), people.end(), compare);
    vector<vector<pair<int, int>>> blocks(1, vector<pair<int, int>>());
    for (auto& person : people) {
      int pos = person.second;
      for (int i = 0; i < (int)blocks.size(); ++i) {
        int n = blocks[i].size();
        if (pos <= n) {
          blocks[i].insert(blocks[i].begin() + pos, person), ++n;
          if (n * n > (int)people.size()) {
            blocks.insert(blocks.begin() + i + 1,
                          vector<pair<int, int>>(blocks[i].begin() + n / 2,
                                                 blocks[i].end()));
            blocks[i].erase(blocks[i].begin() + n / 2, blocks[i].end());
          }
          break;
        }
        pos -= blocks[i].size();
      }
    }
    vector<pair<int, int>> ans;
    for (auto& block : blocks)
      for (auto& person : block) ans.push_back(person);
    return ans;
  }
};
