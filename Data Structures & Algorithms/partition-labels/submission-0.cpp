class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> mpp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mpp[s[i]]=i;
        }
        int endidx=0;
        int startidx=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            endidx=max(endidx,mpp[s[i]]);
            if(i==endidx){
                ans.push_back(endidx-startidx+1);
                startidx=endidx+1;
            }
        }
        return ans;
    }
};
