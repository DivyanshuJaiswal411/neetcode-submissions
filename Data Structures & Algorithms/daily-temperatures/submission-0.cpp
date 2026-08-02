class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n-1;i++){
            int curr=temperatures[i];
            int cnt=0;
            for(int j=i+1;j<n;j++){
                cnt++;
                if(temperatures[j]>curr){
                    ans[i]=cnt;
                    break;
                }
            }
        }
        return ans;
    }
};
