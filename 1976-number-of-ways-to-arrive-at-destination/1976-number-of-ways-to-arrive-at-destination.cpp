class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const int MOD = 1e9 + 7;

        vector<vector<pair<int,int>>> ad(n);

        for(auto it : roads){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            ad[u].push_back({v,t});
            ad[v].push_back({u,t});
        }

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        vector<long long> dist(n, LLONG_MAX);

        vector<unordered_set<int>> parent(n);

        dist[0] = 0;
        pq.push({0,0});

        while(!pq.empty()){

            long long d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(d > dist[node])
                continue;

            for(auto it : ad[node]){

                int newnode = it.first;
                long long time = it.second;

                if(d + time == dist[newnode]){

                    parent[newnode].insert(node);
                }

                else if(d + time < dist[newnode]){

                    dist[newnode] = d + time;

                    parent[newnode].clear();
                    parent[newnode].insert(node);

                    pq.push({dist[newnode], newnode});
                }
            }
        }

        
        vector<int> order(n);

        for(int i = 0; i < n; i++){
            order[i] = i;
        }

        sort(order.begin(), order.end(), [&](int a, int b){
            return dist[a] < dist[b];
        });

        vector<long long> ways(n, 0);
        ways[0] = 1;

        for(int node : order){

            for(int p : parent[node]){

                ways[node] = (ways[node] + ways[p]) % MOD;
            }
        }

        return ways[n-1];
    }
};