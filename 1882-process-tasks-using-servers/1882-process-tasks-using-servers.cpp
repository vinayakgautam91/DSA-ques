class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>> pq;

        
        priority_queue<pair<long long,pair<int,int>>,
        vector<pair<long long,pair<int,int>>>,
        greater<pair<long long,pair<int,int>>>> q;

        vector<int> ans(tasks.size());

        for(int i = 0; i < servers.size(); i++){
            pq.push({servers[i], i});
        }

        long long time = 0;

        for(int i = 0; i < tasks.size(); i++){

            time = max(time, (long long)i);

            
            while(!q.empty() && q.top().first <= time){
                auto temp = q.top();
                q.pop();

                pq.push({temp.second.first, temp.second.second});
            }

            
            if(pq.empty()){
                time = q.top().first;

                while(!q.empty() && q.top().first <= time){
                    auto temp = q.top();
                    q.pop();

                    pq.push({temp.second.first, temp.second.second});
                }
            }

            auto temp = pq.top();
            pq.pop();

            ans[i] = temp.second;

            q.push({
                time + tasks[i],
                {temp.first, temp.second}
            });
        }

        return ans;
    }
};