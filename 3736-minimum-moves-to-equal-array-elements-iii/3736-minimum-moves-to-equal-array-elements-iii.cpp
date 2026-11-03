class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int maxi = nums[n-1];
        long long ans = 0;
        for(int i  = 0;i<n;i++){
            ans += maxi-nums[i];
        }
        return ans;
    }
};