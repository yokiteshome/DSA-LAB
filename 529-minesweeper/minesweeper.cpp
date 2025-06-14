class Solution {
public:
  int getAdjacentMines(vector<vector<char>>& board, int x, int y) {
        int numMines = 0;
        for (int r = x - 1; r <= x + 1; r++) {
            for (int c = y - 1; c <= y + 1; c++) {
                if (r >= 0 && r < board.size() && c >= 0 && c < board[r].size() && board[r][c] == 'M') {
                    numMines++;
                }
            }
        }
        return numMines;
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
         if (board.empty()) return board;

        int x = click[0], y = click[1];
        if (board[x][y] == 'M') {
            board[x][y] = 'X';
        } else {
            int numMines = getAdjacentMines(board, x, y);
            if (numMines) {
                board[x][y] = '0' + numMines;
            } else {
                board[x][y] = 'B';
                for (int r = x - 1; r <= x + 1; r++) {
                    for (int c = y - 1; c <= y + 1; c++) {
                        if (r >= 0 && r < board.size() && c >= 0 && c < board[r].size() && board[r][c] != 'B') {
                            vector<int> nextClick = {r, c};
                            updateBoard(board, nextClick);
                        }
                    }
                }
            }
        }
        return board;
        
    }
};