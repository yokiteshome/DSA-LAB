class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
         int ROWS = isWater.size();
        int COLS = isWater[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> res(ROWS, vector<int>(COLS, -1)); 

       
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (isWater[r][c]) {
                    q.push({r, c});
                    res[r][c] = 0;
                }
            }
        }


        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int h = res[r][c];

            vector<pair<int, int>> neighbors = {
                {r + 1, c}, {r, c + 1}, {r - 1, c}, {r, c - 1}
            };

            for (auto [nr, nc] : neighbors) {
                if (nr < 0 || nc < 0 || nr >= ROWS || nc >= COLS || res[nr][nc] != -1) {
                    continue;
                }
                q.push({nr, nc});
                res[nr][nc] = h + 1;
            }
        }

        return res;
        
    }
};