class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int maxArea = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 1) {
                    int area = dfs(grid, r, c);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
        
    }
     int dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size() || grid[r][c] == 0)
            return 0;

        grid[r][c] = 0; // mark as visited
        int area = 1;

        area += dfs(grid, r + 1, c);
        area += dfs(grid, r - 1, c);
        area += dfs(grid, r, c + 1);
        area += dfs(grid, r, c - 1);

        return area;
    }
};