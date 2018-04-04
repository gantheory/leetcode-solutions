/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
 public:
  vector<pair<pair<int, int>, int>> v;

  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    v.clear();
    int count = 0;
    queue<pair<pair<int, int>, TreeNode*>> q;
    q.push(make_pair(make_pair(-1, count++), root));
    while (!q.empty()) {
      int parentID = q.front().first.first;
      int nowID = q.front().first.second;
      TreeNode* now = q.front().second;
      q.pop();
      if (now == NULL) continue;

      v.push_back(make_pair(make_pair(parentID, nowID), now->val));
      if (count & 1) ++count;
      q.push(make_pair(make_pair(nowID, count++), now->left));
      q.push(make_pair(make_pair(nowID, count++), now->right));
    }

    string ans = "";
    for (auto& p : v)
      ans += to_string(p.first.first) + "," + to_string(p.first.second) + "," +
             to_string(p.second) + ",";
    return ans;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;
    vector<int> tmp;
    int prv = 0;
    for (int i = 1; i < (int)data.size(); ++i)
      if (data[i] == ',') {
        tmp.push_back(stoi(data.substr(prv, i - prv)));
        prv = i + 1;
      }
    v.clear();
    for (int i = 0; i + 2 < (int)tmp.size(); i += 3)
      v.push_back(make_pair(make_pair(tmp[i], tmp[i + 1]), tmp[i + 2]));

    TreeNode* ans = new TreeNode(v[0].second);
    unordered_map<int, TreeNode*> mp;
    mp[v[0].first.second] = ans;
    for (int i = 1; i < (int)v.size(); ++i) {
      int parentID = v[i].first.first;
      int nowID = v[i].first.second;
      int val = v[i].second;
      TreeNode* parent = mp[parentID];
      TreeNode* child = new TreeNode(val);
      if (nowID & 1)
        parent->right = child;
      else
        parent->left = child;
      mp[nowID] = child;
    }
    return ans;
  };
};
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
