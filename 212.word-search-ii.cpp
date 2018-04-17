// Trie {{{
class Node {
 public:
  int parent;
  char c;
  unordered_map<char, int> mp;

  Node(int _p, char _c) : parent(_p), c(_c) {}
};
class Trie {
 public:
  vector<Node> t;

  Trie() { t.emplace_back(-1, '_'); }

  void insert(string word) {
    word += "@";
    int now = 0;
    for (int i = 0; i < (int)word.size(); ++i) {
      if (t[now].mp.count(word[i]) == 0) {
        t[now].mp[word[i]] = t.size();
        t.push_back(Node(now, word[i]));
      }
      now = t[now].mp[word[i]];
    }
  }
};
// }}}
class Solution {
 public:
  unordered_set<string> st;
  void dfs(int x, int y, int ti, Trie& trie, vector<string>& ans,
           vector<vector<char>>& board) {
    if (ti == 0 or board[x][y] == '#') return;
    Node& node = trie.t[ti];
    if (node.mp.count('@')) {
      string now_ans = "";
      int tmp_idx = ti;
      while (tmp_idx != 0) {
        now_ans += trie.t[tmp_idx].c;
        tmp_idx = trie.t[tmp_idx].parent;
      }
      reverse(now_ans.begin(), now_ans.end());
      if (st.count(now_ans) == 0) ans.push_back(now_ans), st.insert(now_ans);
    }

    char c = board[x][y];
    board[x][y] = '#';
    if (x > 0) dfs(x - 1, y, node.mp[board[x - 1][y]], trie, ans, board);
    if (x + 1 < (int)board.size())
      dfs(x + 1, y, node.mp[board[x + 1][y]], trie, ans, board);
    if (y > 0) dfs(x, y - 1, node.mp[board[x][y - 1]], trie, ans, board);
    if (y + 1 < (int)board[x].size())
      dfs(x, y + 1, node.mp[board[x][y + 1]], trie, ans, board);
    board[x][y] = c;
  }
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    if (board.empty() or board[0].empty()) return vector<string>();
    st.clear();

    Trie trie;
    for (string& s : words) trie.insert(s);

    vector<string> ans;
    for (int i = 0; i < (int)board.size(); ++i)
      for (int j = 0; j < (int)board[i].size(); ++j)
        dfs(i, j, trie.t[0].mp[board[i][j]], trie, ans, board);
    return ans;
  }
};
