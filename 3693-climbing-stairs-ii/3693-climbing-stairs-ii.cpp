class Solution {
public:
    long long recurse(int n, vector<int>& costs, int i, vector<long long>& dp) {
        if (i == n) {
            return 0;
        }

        if (dp[i] != -1) {
            return dp[i];
        }

        long long ans = LLONG_MAX;

        if (i + 1 <= n) {
            ans = min(ans, (long long)costs[i] + 1 + recurse(n, costs, i + 1, dp));
        }

        if (i + 2 <= n) {
            ans = min(ans, (long long)costs[i + 1] + 4 + recurse(n, costs, i + 2, dp));
        }

        if (i + 3 <= n) {
            ans = min(ans, (long long)costs[i + 2] + 9 + recurse(n, costs, i + 3, dp));
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, -1);
        return (int)recurse(n, costs, 0, dp);
    }
};