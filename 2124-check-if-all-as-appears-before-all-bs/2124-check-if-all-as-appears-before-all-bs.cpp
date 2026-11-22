class Solution {
public:
    bool checkString(string s) {
        int last = s[0];
        if(s[0] == 'b'){
            for(int i = 1;i<s.size();i++){
                if(s[i] == 'a'){
                    return false;
                }
            }
        }
        else{
            last = 0;
            for(int i = 1;i <s.size();i++){
                if(s[i] == 'a'){
                    if(i-1 != last){
                        return false;
                    }
                    else{
                        last++;
                    }
                }
            }

        }
        return true;
    }
};