class Solution {
public:
    int minChanges(string s) {
        char last = s[0];
        int len = 1;
        int ans = 0;
        int n = s.length();
        for(int i = 1;i<n;i++){
            if(last != s[i] && len%2 == 0){
                last = s[i];
                len = 0;
            }
            else if(last != s[i] && len%2 != 0){
                ans++;
            }
            len++;
        }
        return ans;
    }
};