class Solution {
public:
    int recurse(vector<int>& stones, vector<vector<int>>& dp, int sum1, int i, int total) {
        if (i == stones.size()) {
            return abs(total - 2 * sum1);
        }

        if (dp[i][sum1] != -1) {
            return dp[i][sum1];
        }

        int take = recurse(stones, dp, sum1 + stones[i], i + 1, total);
        int notTake = recurse(stones, dp, sum1, i + 1, total);

        return dp[i][sum1] = min(take, notTake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;

        for (int stone : stones) {
            total += stone;
        }

        vector<vector<int>> dp(n, vector<int>(total + 1, -1));

        return recurse(stones, dp, 0, 0, total);
    }
};