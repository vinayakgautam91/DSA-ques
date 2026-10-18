class Solution {
public:
    int recurse(vector<int>& prices, int i, int hold,
                vector<vector<int>>& dp) {
        int n = prices.size();

        if (i == n) return 0;

        if (dp[i][hold] != -1) {
            return dp[i][hold];
        }

        if (hold) {
            return dp[i][hold] = max(
                recurse(prices, i + 1, 1, dp),
                prices[i] + recurse(prices, i + 1, 0, dp)
            );
        }
        else {
            return dp[i][hold] = max(
                recurse(prices, i + 1, 0, dp),
                -prices[i] + recurse(prices, i + 1, 1, dp)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return recurse(prices, 0, 0, dp);
    }
}; 