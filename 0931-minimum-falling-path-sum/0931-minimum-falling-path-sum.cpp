
class Solution {
public:
    int recurse(vector<vector<int>>& matrix,
                vector<vector<int>>& dp,
                vector<vector<int>>& seen,
                int i, int j) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        if (j < 0 || j >= n) return INT_MAX;
        if (i == m - 1) return matrix[i][j];

        if (seen[i][j]) return dp[i][j];

        int down = recurse(matrix, dp, seen, i + 1, j);
        int left = (j > 0) ? recurse(matrix, dp, seen, i + 1, j - 1) : INT_MAX;
        int right = (j + 1 < n) ? recurse(matrix, dp, seen, i + 1, j + 1) : INT_MAX;

        dp[i][j] = matrix[i][j] + min({down, left, right});
        seen[i][j] = 1;

        return dp[i][j];
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();

        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<vector<int>> seen(m, vector<int>(n, 0));

        int ans = INT_MAX;

        for (int j = 0; j < n; j++) {
            ans = min(ans, recurse(matrix, dp, seen, 0, j));
        }

        return ans;
    }
};
