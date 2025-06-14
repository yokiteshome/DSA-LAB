class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
         unordered_map<int, vector<int>> adj;

        for (int i = 0; i < bombs.size(); ++i) {
            for (int j = i + 1; j < bombs.size(); ++j) {
                long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
                long long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                long long dx = x1 - x2, dy = y1 - y2;
                long long d = dx * dx + dy * dy;

                if (d <= (long long)r1 * r1)
                    adj[i].push_back(j);
                if (d <= (long long)r2 * r2)
                    adj[j].push_back(i);
            }
        }

        function<int(int, unordered_set<int>&)> dfs = [&](int i, unordered_set<int>& visit) -> int {
            if (visit.count(i)) return 0;
            visit.insert(i);
            for (int nei : adj[i])
                dfs(nei, visit);
            return visit.size();
        };

        int res = 0;
        for (int i = 0; i < bombs.size(); ++i) {
            unordered_set<int> visit;
            res = max(res, dfs(i, visit));
        }

        return res;

        
    }
};