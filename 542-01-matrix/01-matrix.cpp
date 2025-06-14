class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
            int rows = mat.size();
        int cols = mat[0].size();
        vector<vector<int>> result(rows, vector<int>(cols));
        vector<vector<int>> seen(rows, vector<int>(cols, 0));
        queue<pair<pair<int, int>, int>> bfsQueue;

        for (int x = 0; x < rows; x++) {
            for (int y = 0; y < cols; y++) {
                if (mat[x][y] == 0) {
                    result[x][y] = 0;
                    bfsQueue.push({{x, y}, 0});
                    seen[x][y] = 1;
                }
            }
        }

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        while (!bfsQueue.empty()) {
            int cx = bfsQueue.front().first.first;
            int cy = bfsQueue.front().first.second;
            int dist = bfsQueue.front().second;
            bfsQueue.pop();

            for (int dir = 0; dir < 4; dir++) {
                int nx = cx + dx[dir];
                int ny = cy + dy[dir];

                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && seen[nx][ny] == 0) {
                    result[nx][ny] = dist + 1;
                    bfsQueue.push({{nx, ny}, dist + 1});
                    seen[nx][ny] = 1;
                }
            }
        }

        return result;
        
    }
};