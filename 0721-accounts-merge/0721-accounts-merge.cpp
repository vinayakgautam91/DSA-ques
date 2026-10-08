#include <algorithm>
class DisjointSet {
public:
    vector<int> parent, size;

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
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int> mp;
        DisjointSet ds(accounts.size()) ;
        for(int i = 0;i<accounts.size();i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j]) != mp.end()){
                    ds.unionBySize(i,mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]] = i;
                }
            }
        }
         vector<vector<string>> ans(accounts.size());
    for(auto it: mp){
        string mail = it.first;
        int node = ds.findUPar(it.second);
        ans[node].push_back(mail);
    }
    vector<vector<string>> finalans;
    for(int i = 0;i<accounts.size();i++){
        if(ans[i].size()==0) continue;
        sort(ans[i].begin(),ans[i].end());

        vector<string> temp;
        temp.push_back(accounts[i][0]);
        for(auto it:ans[i]){
            temp.push_back(it);
        }
        finalans.push_back(temp);
    }
    return finalans;
    }
   


};