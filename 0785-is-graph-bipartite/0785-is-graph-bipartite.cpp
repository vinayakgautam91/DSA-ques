class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        vector<int> visited(graph.size(),-1);
        queue<int> q;
        for(int start = 0; start < graph.size(); start++){
        if(color[start] != 0) continue;

        q.push(start);
        color[start] = 1;

        while(!q.empty()){
            int temp = q.front();
            q.pop();
            for(int i = 0;i < graph[temp].size();i++){
                if(color[graph[temp][i]] == 0){
                    if(color[temp] == 1){
                        color[graph[temp][i]] = 2;
                    }
                    if(color[temp] == 2){
                        color[graph[temp][i]] = 1;
                    }
                }
                else if(color[graph[temp][i]] == color[temp]){
                    return false;
                }
                if(visited[graph[temp][i]] == -1){
                    q.push(graph[temp][i]);
                    visited[graph[temp][i]] = 1;
                }
            }
        }
        }
        
        return true;
    }
};