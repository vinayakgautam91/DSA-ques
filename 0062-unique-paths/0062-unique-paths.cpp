class Solution {
public:
    int recurse(int m,int n,vector<vector<int>>&dp,int i,int j){
        if(i < 0 || j < 0 || i>=m || j>= n){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }
        int down;
        if(i+1<m && dp[i+1][j] != -1){
            down = dp[i+1][j];
        }
        else{
            down = recurse(m,n,dp,i+1,j);
        }
        int right;
        if(j+1 < n && dp[i][j+1] != -1){
            right = dp[i][j+1];
        }
        else{
            right = recurse(m,n,dp,i,j+1);
        }
        return dp[i][j] = down+right;
      
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return recurse(m,n,dp,0,0);
    }
};
//vectot<vector<int>> dp(m,vector<int> (n));
//dp[m-1][n-1] = 0;
//
//
//