class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
         int m = grid.size(), n = grid[0].size();
        vector<int> dirs = {0, -1, 0, 1, 0}; 
        vector<set<int>> rules = {
            {1, 3},  
            {0, 2},  
            {1, 2},  
            {2, 3},  
            {0, 1}, 
            {0, 3}   
        };

        queue<int> q;
        q.push(0); 
        vector<bool> seen(m * n, false);
        seen[0] = true;

        while (!q.empty()) {
            int key = q.front(); q.pop();
            int x = key % n, y = key / n;
            if (x == n - 1 && y == m - 1) return true;

            for (int d : rules[grid[y][x] - 1]) {
                int nx = x + dirs[d];
                int ny = y + dirs[d + 1];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                int nkey = ny * n + nx;
                if (seen[nkey]) continue;
                if (!rules[grid[ny][nx] - 1].count((d + 2) % 4)) continue;

                seen[nkey] = true;
                q.push(nkey);
            }
        }

        return false;
        
    }
};