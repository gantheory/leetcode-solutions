class Solution {
 public:
  vector<vector<bool>> visit;

  bool dfs(int x, int y, int now, vector<vector<char>>& board, string& word) {
    if (visit[x][y]) return false;
    visit[x][y] = true;
    if (now + 1 == (int)word.size()) return true;

    if (x > 0 and board[x - 1][y] == word[now + 1]) {
      bool result = dfs(x - 1, y, now + 1, board, word);
      if (result) return true;
    }
    if (x < (int)board.size() - 1 and board[x + 1][y] == word[now + 1]) {
      bool result = dfs(x + 1, y, now + 1, board, word);
      if (result) return true;
    }
    if (y > 0 and board[x][y - 1] == word[now + 1]) {
      bool result = dfs(x, y - 1, now + 1, board, word);
      if (result) return true;
    }
    if (y < (int)board[0].size() - 1 and board[x][y + 1] == word[now + 1]) {
      bool result = dfs(x, y + 1, now + 1, board, word);
      if (result) return true;
    }

    visit[x][y] = false;
    return false;
  }

  bool exist(vector<vector<char>>& board, string word) {
    visit.resize(board.size());
    for (int i = 0; i < (int)visit.size(); ++i)
      visit[i].resize(board[i].size());

    for (int i = 0; i < (int)board.size(); ++i)
      for (int j = 0; j < (int)board[i].size(); ++j) {
        if (board[i][j] != word[0]) continue;
        bool result = dfs(i, j, 0, board, word);
        if (result) return true;
      }
    return false;
  }
};
