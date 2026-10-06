class Solution {
public:

    void dfs(vector<int>& visited, vector<vector<int>>& adj, int i) {
        visited[i] = 1;

        for (int j = 0; j < adj[i].size(); j++) {
            int node = adj[i][j];

            if (!visited[node]) {
                dfs(visited, adj, node);
            }
        }
    }

    class DisjointSet {
        vector<int> parent, size;

    public:
        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1, 1);

            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;

            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if (ulp_u == ulp_v)
                return;

            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    int makeConnected(int n, vector<vector<int>>& connections) {

        DisjointSet ds(n);

        int cycles = 0;

        // Count extra edges using DSU
        for (auto edge : connections) {

            int u = edge[0];
            int v = edge[1];

            if (ds.findUPar(u) == ds.findUPar(v)) {
                cycles++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }

        // Build adjacency list
        vector<vector<int>> adj(n);

        for (auto edge : connections) {

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

 
        vector<int> visited(n, 0);
        int comp = 0;

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {
                comp++;
                dfs(visited, adj, i);
            }
        }

        if (cycles >= comp - 1) {
            return comp - 1;
        }
        else {
            return -1;
        }
    }
};