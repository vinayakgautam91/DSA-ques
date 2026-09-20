class Solution {
public:
    
    int trap(vector<int>& height) {
        int leftMAX = 0;
        int rightMAX = 0;
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        while(left <= right){
            if(height[left]<height[right]){
                if(height[left]>leftMAX){
                    leftMAX = height[left];
                }
                ans += leftMAX - height[left];
                left++;
            }
            else{
                if(height[right]>rightMAX){
                    rightMAX = height[right];
                }
                ans += rightMAX - height[right];
                right--;
            }
        }
        return ans;
    }
};