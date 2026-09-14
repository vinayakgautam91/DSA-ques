class Solution {
public:
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int> outdegree(n, 0);
        vector<vector<int>> rev(n);

        for(int i = 0; i < n; i++){
            outdegree[i] = graph[i].size();

            for(int j : graph[i]){
                rev[j].push_back(i);
            }
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(outdegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> safe;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int prev : rev[node]){
                outdegree[prev]--;

                if(outdegree[prev] == 0){
                    q.push(prev);
                }
            }
        }

        sort(safe.begin(), safe.end());

        return safe;
    }
};