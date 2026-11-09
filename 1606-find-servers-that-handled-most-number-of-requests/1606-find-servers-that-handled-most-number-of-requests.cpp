class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        int n = arrival.size();

        set<int> available;

       
        for(int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {finishing_time, server_index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > busy;
        vector<int> count(k, 0);
        for(int i = 0;i<n;i++){
           while(!busy.empty() && busy.top().first <= arrival[i]){
            int server = busy.top().second;
            available.insert(server);
            busy.pop();
           }
           if(available.empty()){
            continue;
           }
           int start = i%k;
           auto it = available.lower_bound(start);
           if(it == available.end()){
            it = available.begin();
           }
           int server = *it;
           count[server]++;
           busy.push({arrival[i]+load[i],server});
           available.erase(it);
        }
        int maxi = *max_element(count.begin(),count.end());
        vector<int> ans;
        for(int i = 0; i < k; i++) {
            if(count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;

    }
};