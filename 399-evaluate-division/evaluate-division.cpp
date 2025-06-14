class Solution {
public:
unordered_map<string, vector<pair<string, double>>> graph;
 double dfs(string curr, string target, unordered_set<string>& visited) {
        if (!graph.count(curr)) return -1.0;
        if (curr == target) return 1.0;

        visited.insert(curr);
        for (auto& [neighbor, weight] : graph[curr]) {
            if (visited.count(neighbor)) continue;
            double res = dfs(neighbor, target, visited);
            if (res != -1.0) return res * weight;
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
         for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            graph[a].push_back({b, val});
            graph[b].push_back({a, 1.0 / val});
        }

        vector<double> result;
        for (auto& q : queries) {
            unordered_set<string> visited;
            result.push_back(dfs(q[0], q[1], visited));
        }
        return result;


        
    }
};