class Solution {
public:
vector<int> memo;
    int racecar(int target) {
         if (memo.empty() || memo.size() <= target) {
            memo.assign(target + 1, -1);
        }

        if (target == 0) return 0;

    
        if (memo[target] != -1) return memo[target];

        int n = 1;
        while ((1 << n) - 1 < target) {
            ++n;
        }

       
        if ((1 << n) - 1 == target) {
            memo[target] = n;
        } else {
            
            int overshoot = (1 << n) - 1;
            memo[target] = n + 1 + racecar(overshoot - target);

          
            for (int m = 0; m < n - 1; ++m) {
                int partialForward = (1 << (n - 1)) - 1;
                int reverseDistance = (1 << m) - 1;
                int position = partialForward - reverseDistance;
                memo[target] = min(memo[target], (n - 1) + 1 + m + 1 + racecar(target - position));
            }
        }

        return memo[target];
        
    }
};