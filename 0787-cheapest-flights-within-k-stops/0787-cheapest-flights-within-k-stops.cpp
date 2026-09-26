class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {
        vector<vector<pair<int, int>>> ad(n);

        for (const auto& flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int price = flight[2];
            ad[u].push_back({v, price});
        }

        
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        
        vector<vector<int>> dist(k + 2, vector<int>(n, INT_MAX));
        dist[0][src] = 0;

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int flightsUsed = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (cost != dist[flightsUsed][node] ||
                flightsUsed == k + 1) {
                continue;
            }

            for (const auto& edge : ad[node]) {
                int adjNode = edge.first;
                int price = edge.second;
                int newCost = cost + price;

                if (newCost < dist[flightsUsed + 1][adjNode]) {
                    dist[flightsUsed + 1][adjNode] = newCost;
                    q.push({flightsUsed + 1, {adjNode, newCost}});
                }
            }
        }

        int answer = INT_MAX;
        for (int flightsUsed = 0; flightsUsed <= k + 1; flightsUsed++) {
            answer = min(answer, dist[flightsUsed][dst]);
        }

        return answer == INT_MAX ? -1 : answer;
    }
};