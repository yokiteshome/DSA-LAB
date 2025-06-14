class Solution {
public:
void dfs(std::vector<std::vector<int>>& isConnected, int i, int j) {
        isConnected[i][j] = 0;

        for (auto k = 0; k < isConnected.size(); k++) {
            if (isConnected[j][k] == 1)
                dfs(isConnected, j, k);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         int maxProvinces = 0;
        int numProvinces = 0; 

        for (auto i = 0; i < isConnected.size(); i++) {
            for (auto j = 0; j < isConnected[0].size(); j++) {
                if (isConnected[i][j] == 1) {
                    numProvinces++;
                    dfs(isConnected, i, j);
                }
            }
        }
        return numProvinces;
        
        
    }
};