class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
         set<int> opened;
        stack<int> roomStack;

        opened.insert(0);  
        for (const auto& key : rooms[0]) {
            roomStack.push(key);
        }

        while (!roomStack.empty()) {
            int room = roomStack.top();
            roomStack.pop();

            if (opened.find(room) == opened.end()) {
                opened.insert(room);
                for (const auto& key : rooms[room]) {
                    roomStack.push(key);
                }
            }
        }

        return (opened.size() == rooms.size());
        
    }
};