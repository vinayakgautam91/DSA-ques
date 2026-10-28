class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        
        vector<int> curr(amount + 1, INT_MAX);
        curr[amount] = 0;
        for (int i = n - 1; i >= 0; i--) {
            curr[amount] = 0;
            for (long long total = amount - 1; total >= 0; total--) {
                int take = INT_MAX;
                int skip = curr[total];

          
                if (total + coins[i] <= amount) {
                    int remaining = curr[total + coins[i]];

                    if (remaining != INT_MAX) {
                        take = 1 + remaining;
                    }
                }

                
                curr[total] = min(take, skip);
            }
           
        }
        return curr[0] == INT_MAX?-1:curr[0];
    }
};