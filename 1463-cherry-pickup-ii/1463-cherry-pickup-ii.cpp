class Solution {
public:
    int recurse(vector<vector<vector<int>>>& dp,
                vector<vector<int>>& grid,
                int i, int j1, int j2) {

        int m = grid.size();
        int n = grid[0].size();

    
        if (j1 < 0 || j1 >= n || j2 < 0 || j2 >= n) {
            return -1e9;
        }

        if (i == m - 1) {
            if (j1 == j2) {
                return grid[i][j1];
            }
            return grid[i][j1] + grid[i][j2];
        }

       
        if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }

        int cherries;

        if (j1 == j2) {
            cherries = grid[i][j1];
        } else {
            cherries = grid[i][j1] + grid[i][j2];
        }

        int maxi = INT_MIN;

       
        for (int dj1 = -1; dj1 <= 1; dj1++) {
            for (int dj2 = -1; dj2 <= 1; dj2++) {
                int nj1 = j1 + dj1;
                int nj2 = j2 + dj2;

                maxi = max(maxi,
                    recurse(dp, grid, i + 1, nj1, nj2));
            }
        }

        return dp[i][j1][j2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(
                n, vector<int>(n, -1)
            )
        );

        return recurse(dp, grid, 0, 0, n - 1);
    }
};