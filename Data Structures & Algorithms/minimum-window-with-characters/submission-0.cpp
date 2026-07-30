class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<int> index(256,0);
        for(char c:t){
            index[c]++;
        }
        int l=0;
        int r=0;
        int cnt=0;
        int idx=-1;
        int minlen=INT_MAX;
        while(r<n){
            if(index[s[r]]>0) cnt++;
            index[s[r]]--;
            while(cnt==m){
                if(r-l+1<minlen){
                    minlen=r-l+1;
                    idx=l;
                }
                index[s[l]]++;
                if(index[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        if(idx==-1) return "";
        return s.substr(idx,minlen);
    }
};
