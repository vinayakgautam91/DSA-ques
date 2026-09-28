class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {

        vector<int> steps(1001, INT_MAX);
        queue<pair<int,int>> q;

        steps[start] = 0;
        q.push({start, 0});

        while(!q.empty()) {

            int number = q.front().first;
            int step = q.front().second;
            q.pop();

            for(int i = 0; i < nums.size(); i++) {

                int x = nums[i];
                int nstep = step + 1;

                int a = number + x;
                int b = number - x;
                int c = number ^ x;

       
                if(a == goal || b == goal || c == goal)
                    return nstep;


                if(a >= 0 && a <= 1000 && steps[a] == INT_MAX) {
                    steps[a] = nstep;
                    q.push({a, nstep});
                }

                if(b >= 0 && b <= 1000 && steps[b] == INT_MAX) {
                    steps[b] = nstep;
                    q.push({b, nstep});
                }

                if(c >= 0 && c <= 1000 && steps[c] == INT_MAX) {
                    steps[c] = nstep;
                    q.push({c, nstep});
                }
            }
        }

        return -1;
    }
};