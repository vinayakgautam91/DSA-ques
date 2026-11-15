class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long count_odd = 0;
        long long count_even = 1; 
        long long sum = 0;
        long long ans = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            if(sum % 2 != 0){
                count_odd++;
                ans += count_even;
            }
            else{
                count_even++;
                ans += count_odd;
            }
        }

        return ans % 1000000007; 
    }
};