class Solution {
public:
    bool dfs(int i, vector<int>& visited,
             vector<vector<int>>& ad, vector<int>& path) {

        visited[i] = 1;
        path[i] = 1;

        for (int n : ad[i]) {

            if (!visited[n]) {
                if (!dfs(n, visited, ad, path))
                    return false;
            }
            else if (path[n]) {
                return false;  // cycle found
            }
        }

        path[i] = 0;  

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& pre) {

        vector<int> visited(numCourses, 0);
        vector<int> path(numCourses, 0);
        vector<vector<int>> ad(numCourses);

        for (auto p : pre) {
            int u = p[0];
            int v = p[1];

            ad[u].push_back(v);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (!dfs(i, visited, ad, path))
                    return false;
            }
        }

        return true;
    }
};