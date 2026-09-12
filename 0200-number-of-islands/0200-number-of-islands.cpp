class Solution {
public:
    void dfs(int i,int j,vector<vector<int>> &visited,vector<vector<char>>& grid){
        if( i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0'){
            return;
        }
        else if(visited[i][j] == 1){
            return;
        }

        visited[i][j] = 1;
        dfs(i-1,j,visited,grid);
        dfs(i+1,j,visited,grid);
        dfs(i,j-1,visited,grid);
        dfs(i,j+1,visited,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(visited[i][j] != 1 && grid[i][j] == '1'){
                    ans++;
                    dfs(i,j,visited,grid);
                }
            }
        }
        return ans;
    }
};