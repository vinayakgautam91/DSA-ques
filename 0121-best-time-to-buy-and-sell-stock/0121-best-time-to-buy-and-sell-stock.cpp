class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size();
       int maxi = INT_MIN;
       vector<int> next(n);
        for(int i = n-1;i>=0;i--){
            if(prices[i] > maxi){
                maxi = prices[i];
            }
            next[i] = maxi;
        }
        int profit = INT_MIN;
        for(int i = 0;i<n;i++){
            profit = max(profit,next[i]-prices[i]);
        }
        return profit;
    }
};