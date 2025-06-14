class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
         if (source == target) return 0;

        unordered_map<int, vector<int>> stopToRoutes;
        for (int i = 0; i < routes.size(); ++i) {
            for (int stop : routes[i]) {
                stopToRoutes[stop].push_back(i);
            }
        }

        queue<int> q;
        unordered_set<int> visitedStops;
        unordered_set<int> visitedRoutes;

        q.push(source);
        visitedStops.insert(source);

        int buses = 0;

        while (!q.empty()) {
            int size = q.size();
            ++buses;

            for (int i = 0; i < size; ++i) {
                int currStop = q.front();
                q.pop();

                for (int route : stopToRoutes[currStop]) {
                    if (visitedRoutes.count(route)) continue;

                    visitedRoutes.insert(route);
                    for (int nextStop : routes[route]) {
                        if (nextStop == target) return buses;
                        if (!visitedStops.count(nextStop)) {
                            visitedStops.insert(nextStop);
                            q.push(nextStop);
                        }
                    }
                }
            }
        }

        return -1;
        
    }
};