class Solution {
 public:
  void gameOfLife(vector<vector<int>>& board) {
    for (int i = 0; i < (int)board.size(); ++i)
      for (int j = 0; j < (int)board[i].size(); ++j) {
        int count = 0;
        for (int dx = -1; dx <= 1; ++dx)
          for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 and dy == 0) continue;
            int x = i + dx, y = j + dy;
            if (x < 0 or x >= (int)board.size() or y < 0 or
                y >= (int)board[i].size())
              continue;
            count += (board[x][y] & 1) == 1;
          }
        if (board[i][j] & 1) {
          if (2 <= count and count <= 3) board[i][j] += 2;
        } else {
          if (count == 3) board[i][j] += 2;
        }
      }

    for (int i = 0; i < (int)board.size(); ++i)
      for (int j = 0; j < (int)board[i].size(); ++j) board[i][j] >>= 1;
  }
};
