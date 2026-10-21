class Solution {
public:
    int recurse(vector<int> &arr,long long sum,int index,vector<vector<long long>> &dp){
        if(sum < 0) return false;
        if(sum == 0){
            return true;
        }
        if(index == arr.size()){
            return false;
        }
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        bool ans = false;;
        ans = ans || recurse(arr,sum,index+1,dp);
        ans = ans || recurse(arr,sum-arr[index],index+1,dp);
        return dp[index][sum] = ans;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i<n;i++){
            sum += nums[i];
        }
        if(sum%2 != 0){
            return false;
        }
        long long target = sum/2;
        vector<vector<long long>> dp(n,vector<long long>(target+1,-1));
        return recurse(nums,target,0,dp);
    }
};