class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<int,string>> q;
        q.push({1,beginWord});
        st.erase(beginWord);
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int steps=it.first;
            string word=it.second;
            if(word==endWord) return steps;
            for(int i=0;i<word.size();i++){
                char original=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        st.erase(word);
                        q.push({steps+1,word});
                    }
                }
                word[i]=original;
            }
        }
        return 0;
    }
};
