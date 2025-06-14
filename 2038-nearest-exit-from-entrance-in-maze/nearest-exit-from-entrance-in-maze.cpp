class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         int m = maze.size();
        int n = maze[0].size();

        std::queue<std::vector<int>> q;

        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));

        int entrancerow = entrance[0];
        int entrancecol = entrance[1];

        q.push({entrancerow, entrancecol, 0});
        visited[entrancerow][entrancecol] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {
            std::vector<int> current = q.front();
            q.pop();

            int r = current[0];
            int c = current[1];
            int steps = current[2];

            for (int i = 0; i < 4; ++i) {
                int next_r = r + dr[i];
                int next_c = c + dc[i];

                if (next_r >= 0 && next_r < m && next_c >= 0 && next_c < n &&
                    maze[next_r][next_c] == '.' && !visited[next_r][next_c]) {

                    if ((next_r == 0 || next_r == m - 1 || next_c == 0 || next_c == n - 1)) {
                        return steps + 1;
                    }

                    visited[next_r][next_c] = true;
                    q.push({next_r, next_c, steps + 1});
                }
            }
        }

        return -1;
        
    }
};