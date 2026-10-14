class Solution {
public:
    int recurse(vector<vector<int>> obstacleGrid,vector<vector<long long>>&dp,int i,int j){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(i < 0 || j < 0 || i>=m || j>= n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        if(obstacleGrid[i][j] == 1){
            return dp[i][j] = 0;
        }
        int down;
        if(i+1<m && dp[i+1][j] != -1){
            down = dp[i+1][j];
        }
        else{
            down = recurse(obstacleGrid,dp,i+1,j);
        }
        int right;
        if(j+1 < n && dp[i][j+1] != -1){
            right = dp[i][j+1];
        }
        else{
            right = recurse(obstacleGrid,dp,i,j+1);
        }
        return dp[i][j] = down+right;
      
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) return 0;
        vector<vector<long long>> dp(m, vector<long long> (n,-1));
        return recurse(obstacleGrid,dp,0,0);
    }
};