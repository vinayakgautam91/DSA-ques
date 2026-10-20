class Solution {
public:
    int recurse(vector<int>& prices, int i, int hold,
                vector<vector<vector<int>>>& dp,int cool) {
        int n = prices.size();

        if (i == n) return 0;

        if (dp[i][hold][cool] != -1) {
            return dp[i][hold][cool];
        }

        if (hold) {
            return dp[i][hold][cool] = max(
                recurse(prices, i + 1, 1, dp,0),
                prices[i] + recurse(prices, i + 1, 0, dp,1)
            );
        }
        else if(cool == 1){
            return dp[i][hold][cool] =recurse(prices, i + 1, 0, dp,0);
        }
        else{
            return dp[i][hold][cool] = max(
                recurse(prices, i + 1, 0, dp,0),
                -prices[i] + recurse(prices, i + 1, 1, dp,1)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2,-1)));

        return recurse(prices, 0, 0, dp,0);
    }
}; 