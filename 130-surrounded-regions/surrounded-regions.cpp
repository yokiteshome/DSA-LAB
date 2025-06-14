class Solution {
public:
    void dfs(vector<vector<char>>& grid, int r, int c)
    {
        int R = grid.size();
        int C = grid[0].size();

        if (r < 0 || r >= R || c < 0 || c >= C || grid[r][c] != 'O') {
            return;
        }

        grid[r][c] = 'Z';

        int dr[4] = {1, -1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int i = 0; i < 4; i++)
        {
            int rr = r + dr[i];
            int cc = c + dc[i];
            dfs(grid, rr, cc);
        }
    }

    void solve(vector<vector<char>>& board) {
         int R = board.size();
    if (R == 0) return;  
    int C = board[0].size();

    for (int j = 0; j < C; j++)
    {
        if (board[0][j] == 'O') {
            dfs(board, 0, j);
        }
        if (board[R - 1][j] == 'O') {
            dfs(board, R - 1, j);
        }
    }
    for (int i = 0; i < R; i++)
    {
        if (board[i][0] == 'O') {
            dfs(board, i, 0);
        }
        if (board[i][C - 1] == 'O') {
            dfs(board, i, C - 1);
        }
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (board[i][j] == 'Z') {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O') {
                board[i][j] = 'X';
            }
        }
    }
}
        
        
};