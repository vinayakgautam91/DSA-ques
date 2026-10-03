class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
      int n = grid.size();
      priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
      vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
      //{current_required_water,{row,col}}
      vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
      dist[0][0] = grid[0][0];
      pq.push({grid[0][0], {0,0}});
      while(!pq.empty()){
        int current_req = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();
        if(dist[r][c] > current_req){
            continue;
        }
        for(auto dir:directions){
            int nr = r + dir[0];
            int nc = c + dir[1];
            if(nr < 0 || nc < 0 || nr>=n|| nc>=n){
                continue;
            }
            int newdist = max(current_req,grid[nr][nc]);
            if(newdist < dist[nr][nc]){
                dist[nr][nc] = newdist;
                pq.push({newdist,{nr,nc}});
            }
        }
      }
      return dist[n-1][n-1];
    }
};