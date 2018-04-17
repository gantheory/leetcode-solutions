class Solution {
 public:
  void dfs(int x, int y, vector<vector<char>>& board,
           vector<vector<bool>>& visit) {
    if (visit[x][y]) return;
    visit[x][y] = true;

    if (x > 0) dfs(x - 1, y, board, visit);
    if (x + 1 < (int)board.size()) dfs(x + 1, y, board, visit);
    if (y > 0) dfs(x, y - 1, board, visit);
    if (y + 1 < (int)board[x].size()) dfs(x, y + 1, board, visit);
  }
  void solve(vector<vector<char>>& board) {
    if (board.empty() or board[0].empty()) return;
    vector<vector<bool>> visit(board.size(),
                               vector<bool>(board[0].size(), false));
    for (int i = 0; i < (int)board.size(); ++i)
      for (int j = 0; j < (int)board[i].size(); ++j)
        if (board[i][j] == 'X') visit[i][j] = true;

    for (int i = 0; i < (int)board.size(); ++i)
      dfs(i, 0, board, visit), dfs(i, board[i].size() - 1, board, visit);
    for (int j = 0; j < (int)board[0].size(); ++j)
      dfs(0, j, board, visit), dfs(board.size() - 1, j, board, visit);

    for (int i = 0; i < (int)board.size(); ++i)
      for (int j = 0; j < (int)board[i].size(); ++j)
        if (visit[i][j] == false) board[i][j] = 'X';
  }
};
