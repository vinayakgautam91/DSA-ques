class Solution {
public:
    int recurse(vector<int>& prices, int i, int hold,
                vector<vector<vector<int>>>& dp,int t) {
        int n = prices.size();

        if (i == n) return 0;
        if(t == 2) return 0;
        if (dp[i][hold][t] != -1) {
            return dp[i][hold][t];
        }

        if (hold) {
            return dp[i][hold][t] = max(
                recurse(prices, i + 1, 1, dp,t),
                prices[i] + recurse(prices, i + 1, 0, dp,t+1)
            );
        }
        else {
            return dp[i][hold][t] = max(
                recurse(prices, i + 1, 0, dp,t),
                -prices[i] + recurse(prices, i + 1, 1, dp,t)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int> (3,-1)));

        return recurse(prices, 0, 0, dp,0);
    }
}; 