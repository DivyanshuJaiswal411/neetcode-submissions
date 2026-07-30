class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> mpp1;
        for(char c:s1) mpp1[c]++;
        int size1=s1.size();
        int size2=s2.size();
        int l=0;
        int r=size1-1;
        while(r<size2){
            map<char,int> temp;
            temp=mpp1;
            for(int i=l;i<=r;i++){
                if(temp[s2[i]]){
                    temp[s2[i]]--;
                    if(temp[s2[i]]==0) temp.erase(s2[i]);
                }
            }
            if(temp.empty()) return true;
            l++;
            r++;
        }
        return false;
    }
};
