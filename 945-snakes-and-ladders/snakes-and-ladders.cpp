class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
         int size = board.size();
        int goal = size * size;
        queue<int> posQueue;
        posQueue.push(1);
        vector<bool> isSeen(goal + 1, false);
        isSeen[1] = true;

        int steps = 0;

        while (!posQueue.empty()) {
            int qSize = posQueue.size();

            for (int i = 0; i < qSize; ++i) {
                int current = posQueue.front();
                posQueue.pop();

                if (current == goal)
                    return steps;

                for (int move = current + 1; move <= min(current + 6, goal); ++move) {
                    int square = move;

                    int r = (move - 1) / size;
                    int c = (move - 1) % size;

                    if (r % 2 == 1)
                        c = size - 1 - c;

                    r = size - 1 - r;

                    if (board[r][c] != -1)
                        square = board[r][c];

                    if (!isSeen[square]) {
                        isSeen[square] = true;
                        posQueue.push(square);
                    }
                }
            }

            steps++;
        }

        return -1;
        
    }
};