#include <queue>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        priority_queue<pair<double,int>> pq;
        vector<vector<pair<int,double>>> ad(n);
        pq.push({1,start_node});
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double po = succProb[i];
            ad[u].push_back({v,po});
            ad[v].push_back({u,po});
        }
        vector<double> prob(n,0);
        prob[start_node] = 1;
        while(!pq.empty()){
            double p = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(p < prob[node]){
                continue;
            }
            for(auto it:ad[node]){
                int nextnode = it.first;
                double pro = it.second;
                if(pro*prob[node] > prob[nextnode]){
                    prob[nextnode] = pro*prob[node];
                    pq.push({prob[nextnode],nextnode});
                }
            }
        }
        return prob[end_node];
    }
};