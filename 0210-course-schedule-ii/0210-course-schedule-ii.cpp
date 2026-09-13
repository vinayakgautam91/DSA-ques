class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> ad(numCourses);

        for (auto p : pre) {
            int u = p[0]; 
            int v = p[1];
            indegree[u]++;
            ad[v].push_back(u);
        }

        queue<int> q;

        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node);

            for(int n : ad[node]) {
                indegree[n]--;

                if(indegree[n] == 0) {
                    q.push(n);
                }
            }
        }

        if(topo.size() != numCourses) {
            return {};
        }

        return topo;
    }
};