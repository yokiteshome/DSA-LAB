class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
         const vector<int> dx = {0, 0, -1, 1};
        const vector<int> dy = {-1, 1, 0, 0};

        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> bfsQueue;

        // Enqueue all land cells
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    bfsQueue.push({i, j});
                    grid[i][j] = 2;  // Mark as visited
                }
            }
        }

        // If all are land or all are water, return -1
        if (bfsQueue.empty() || bfsQueue.size() == rows * cols) {
            return -1;
        }

        int maxDistance = 0;

        // BFS traversal
        while (!bfsQueue.empty()) {
            int levelSize = bfsQueue.size();

            while (levelSize--) {
                auto [x, y] = bfsQueue.front();
                bfsQueue.pop();

                for (int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if (nx >= 0 && ny >= 0 && nx < rows && ny < cols && grid[nx][ny] == 0) {
                        bfsQueue.push({nx, ny});
                        grid[nx][ny] = 2;  // Mark as visited
                    }
                }
            }

            maxDistance++;
        }

        return maxDistance - 1;
        
    }
};