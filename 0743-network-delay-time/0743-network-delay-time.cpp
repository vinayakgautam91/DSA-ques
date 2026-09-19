#include <queue>
#include <vector>
#include <climits>
#include <functional>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > q;

        vector<vector<pair<int,int>>> ad(n + 1);


        for(auto time : times){
            int u = time[0];
            int v = time[1];
            int w = time[2];

            ad[u].push_back({v,w});
        }


        vector<int> dist(n + 1, INT_MAX);

        dist[k] = 0;
        q.push({0, k});


        while(!q.empty()){

            int d = q.top().first;
            int node = q.top().second;
            q.pop();


            if(d > dist[node])
                continue;

            for(auto p : ad[node]){

                int v = p.first;
                int w = p.second;

                if(dist[v] > dist[node] + w){

                    dist[v] = dist[node] + w;

                    q.push({dist[v], v});
                }
            }
        }


        int maxi = 0;

        for(int i = 1; i <= n; i++){

            if(dist[i] == INT_MAX)
                return -1;

            maxi = max(maxi, dist[i]);
        }

        return maxi;
    }
};