/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        std::map<int, std::pair<int, std::vector<int>>> map;

        for (int i = 0; i < employees.size(); i++) {
            map[employees[i]->id] = {employees[i]->importance, employees[i]->subordinates};
        }

        std::queue<int> queue;
        queue.push(id);

        while (!queue.empty()) {
            int size = queue.size();
            while (size) {
                int temp = queue.front();
                queue.pop();
                ans += map[temp].first;

                for (int i = 0; i < map[temp].second.size(); i++) {
                    queue.push(map[temp].second[i]);
                }
                size--;
            }
        }
        return ans;
        
        
    }
};