class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
         unordered_set<string> visited(deadends.begin(), deadends.end());

        if (visited.count("0000")) {
            return -1;
        }

        auto getChildren = [](const string& lock) {
            vector<string> result;
            for (int i = 0; i < 4; i++) {
                string up = lock;
                up[i] = (up[i] - '0' + 1) % 10 + '0';
                result.push_back(up);

                string down = lock;
                down[i] = (down[i] - '0' - 1 + 10) % 10 + '0';
                result.push_back(down);
            }
            return result;
        };

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        while (!q.empty()) {
            auto [lock, turns] = q.front();
            q.pop();

            if (lock == target) {
                return turns;
            }

            for (const auto& next : getChildren(lock)) {
                if (!visited.count(next)) {
                    visited.insert(next);
                    q.push({next, turns + 1});
                }
            }
        }

        return -1;
        
    }
};