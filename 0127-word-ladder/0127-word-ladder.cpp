class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st(wordList.begin(), wordList.end());

        if(st.find(endWord) == st.end())
            return 0;

        queue<string> q;
        q.push(beginWord);

        int level = 1;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                string curr = q.front();
                q.pop();

                if(curr == endWord)
                    return level;

                for(int i = 0; i < curr.size(); i++) {
                    string temp = curr;

                    for(char ch = 'a'; ch <= 'z'; ch++) {
                        temp[i] = ch;

                        if(st.find(temp) != st.end()) {
                            q.push(temp);
                            st.erase(temp);
                        }
                    }
                }
            }

            level++;
        }

        return 0;
    }
};