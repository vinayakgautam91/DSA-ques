class Solution {
public:
    

    bool canFinish(int numCourses, vector<vector<int>>& pre) {

        vector<int> indegree(numCourses, 0);
        vector<int> path(numCourses, 0);
        vector<vector<int>> ad(numCourses);

        for (auto p : pre) {
            int u = p[0];
            int v = p[1];
            indegree[v]++;
            ad[u].push_back(v);
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(int n:ad[node]){
                indegree[n]--;
                if(indegree[n] == 0){
                    q.push(n);
                }
            }
        }
        
       

        return count == numCourses;
    }
};