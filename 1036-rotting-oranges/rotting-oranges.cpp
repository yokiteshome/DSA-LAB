class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        if (rows == 0) {
            return 0; 
        }
        int cols = grid[0].size();

        std::queue<std::pair<int, int>> rottenQueue;
        int freshCount = 0;
        int minutes = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rottenQueue.push(std::make_pair(i, j));
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

       
        if (freshCount == 0) {
            return 0;
        }


        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

       
        while (!rottenQueue.empty() && freshCount > 0) {
            minutes++; 
            int levelSize = rottenQueue.size(); 

            for (int i = 0; i < levelSize; ++i) {
                std::pair<int, int> current = rottenQueue.front();
                rottenQueue.pop();

                int r = current.first;
                int c = current.second;

                
                for (int k = 0; k < 4; ++k) {
                    int newR = r + dx[k];
                    int newC = c + dy[k];

                    
                    if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == 1) {
                        grid[newR][newC] = 2; 
                        freshCount--;        
                        rottenQueue.push(std::make_pair(newR, newC)); 
                    }
                }
            }
        }

       
        if (freshCount > 0) {
            return -1;
        } else {
            return minutes;

        }
    }
};