class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        long long sum = INT_MAX;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long curr = 0;
            for(int j = i;j<n;j++){
                curr += nums[j];
                if(curr > 0){
                    if((j-i+1) >= l && (j-i+1) <= r){
                    sum = min(curr,sum);
                    }
                }
            }
        }
        return sum==INT_MAX?-1:sum;
        
    }
};