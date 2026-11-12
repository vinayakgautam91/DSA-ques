class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxi_i = 1;
        int maxi_d = 1;
        int count_i = 1;
        int count_d = 1;

        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                count_i++;
            } 
            else{
                count_i = 1;
            }

            if(nums[i] < nums[i-1]){
                count_d++;
            }
            else{
                count_d = 1;
            }

            maxi_d = max(maxi_d, count_d);
            maxi_i = max(maxi_i, count_i);
        }

        return max(maxi_i, maxi_d);
    }
};