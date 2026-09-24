class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        priority_queue<
            pair<int,pair<int,int>>,
            vector<pair<int,pair<int,int>>>,
            greater<pair<int,pair<int,int>>>
        > pq;

        vector<vector<int>> effort(m, vector<int>(n, INT_MAX));

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<vector<int>> dir = {
            {1,0}, {0,1}, {-1,0}, {0,-1}
        };

        while(!pq.empty()) {

            int eff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();

            if(eff > effort[i][j])
                continue;

            for(auto dire : dir) {

                int newi = i + dire[0];
                int newj = j + dire[1];

                if(newi < 0 || newj < 0 ||
                   newi >= m || newj >= n)
                    continue;

                int edgeEffort =
                    abs(heights[i][j] - heights[newi][newj]);

                int newEff = max(eff, edgeEffort);

                if(newEff < effort[newi][newj]) {

                    effort[newi][newj] = newEff;

                    pq.push({newEff, {newi, newj}});
                }
            }
        }

        return effort[m-1][n-1];
    }
};