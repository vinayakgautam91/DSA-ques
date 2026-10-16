class Solution {
public:
    int recurse(vector<vector<int>>& dp, vector<vector<int>>& triangle, int n, int i,vector<vector<bool>> &seen) {

        if (n == triangle.size()) {
            return 0;
        }

        if (seen[n][i] != false) {
            return dp[n][i];
        }
        seen[n][i] = true;

        return dp[n][i] = triangle[n][i] + min(
            recurse(dp, triangle, n + 1, i,seen),
            recurse(dp, triangle, n + 1, i + 1,seen)
        );
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        

        vector<vector<int>> dp(n);
        vector<vector<bool>> seen(n);
        for (int i = 0; i < n; i++) {
        dp[i] = vector<int>(i + 1, -1);
        seen[i] = vector<bool>(i+1,false);
        }

        return recurse(dp, triangle, 0, 0,seen);
    }
};