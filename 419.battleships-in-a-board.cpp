class Solution {
 public:
  int countBattleships(vector<vector<char>>& board) {
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < (int)board.size(); ++i)
      for (int j = 0; j < (int)board[i].size(); ++j) {
        if (board[i][j] != 'X') continue;
        int num = 0;
        if (i > 0) num += board[i - 1][j] == 'X';
        if (i + 1 < (int)board.size()) num += board[i + 1][j] == 'X';
        if (j > 0) num += board[i][j - 1] == 'X';
        if (j + 1 < (int)board[i].size()) num += board[i][j + 1] == 'X';
        if (num == 0) ++ans2;
        if (num == 1) ++ans1;
      }
    return (ans1 >> 1) + ans2;
  }
};
