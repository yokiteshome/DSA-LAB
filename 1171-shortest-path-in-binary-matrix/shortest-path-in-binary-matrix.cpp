class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0},
            {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
        };

        int gridSize = grid.size();

        if (grid[0][0] != 0 || grid[gridSize - 1][gridSize - 1] != 0) 
            return -1;

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;
            int stepCount = grid[x][y];

            if (x == gridSize - 1 && y == gridSize - 1) {
                return stepCount;
            }

            for (auto& dir : directions) {
                int dx = dir.first;
                int dy = dir.second;

                int newX = x + dx;
                int newY = y + dy;

                if ((newX >= 0 && newX < gridSize) &&
                    (newY >= 0 && newY < gridSize) &&
                    (grid[newX][newY] == 0)) {

                    q.push({newX, newY});
                    grid[newX][newY] = stepCount + 1;
                }
            }
        }

        return -1;
        
    }
};