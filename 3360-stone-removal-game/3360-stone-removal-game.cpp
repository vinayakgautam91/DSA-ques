class Solution {
public:
    bool canAliceWin(int n) {
        int s = 10;
        while(n >= s){
            n -= s;
            s--;
        }
        if(s%2 == 0){
            return false;
        }
        else if(s == 10){
            return false;
        }
        return true;
    }
};