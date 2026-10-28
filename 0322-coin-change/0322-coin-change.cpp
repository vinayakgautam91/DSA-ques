class Solution {
public:
    int recurse(vector<int>& coins, int amount, long long total, int i,
                vector<vector<long long>>& dp) {
        if (total == amount) {
            return 0;
        }
        if (total > amount || i == coins.size()) {
            return INT_MAX;
        }

        if (dp[i][total] != -1) {
            return dp[i][total];
        }

        int ans = INT_MAX;

        int take = recurse(coins, amount, total + coins[i], i, dp);
        if (take != INT_MAX) {
            ans = min(ans, take + 1);
        }

        int skip = recurse(coins, amount, total, i + 1, dp);
        ans = min(ans, skip);

        return dp[i][total] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<long long>> dp(n, vector<long long>(amount + 1, -1));

        int ans = recurse(coins, amount, 0, 0, dp);
        return ans == INT_MAX ? -1 : ans;
    }
};