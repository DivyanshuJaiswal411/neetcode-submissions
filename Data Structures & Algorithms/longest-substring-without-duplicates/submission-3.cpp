class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> index(257,-1);
        int n=s.size();
        int l=0;
        int maxlen=0;
        for(int r=0;r<n;r++){
            if(index[s[r]]!=-1){
                if(index[s[r]]>=l) l=index[s[r]]+1;
            }
            maxlen=max(maxlen,r-l+1);
            index[s[r]]=r;
        }
        return maxlen;
    }
};
