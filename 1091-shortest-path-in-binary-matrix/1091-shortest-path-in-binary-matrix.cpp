class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int m = grid.size();

        if (m == 0 || grid[0].empty()) {
            return -1;
        }

        int n = grid[0].size();

        if (grid[0][0] == 1 || grid[m - 1][n - 1] == 1) {
            return -1;
        }

        queue<vector<int>> q;
        q.push({0, 0, 1});
        grid[0][0] = 1;

        vector<vector<int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},   {1, 1}
        };

        while (!q.empty()) {
            int i = q.front()[0];
            int j = q.front()[1];
            int d = q.front()[2];
            q.pop();

            if (i == m - 1 && j == n - 1) {
                return d;
            }

            for (auto& direction : dir) {
                int nextRow = i + direction[0];
                int nextCol = j + direction[1];

                if (nextRow >= 0 && nextRow < m &&
                    nextCol >= 0 && nextCol < n &&
                    grid[nextRow][nextCol] == 0) {

                    grid[nextRow][nextCol] = 1;
                    q.push({nextRow, nextCol, d + 1});
                }
            }
        }

        return -1;
    }
};