class Solution {
public:
    int f(int idx,vector<int>& nums,int n,vector<int>& dp){
        if(idx>=n-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mini=1e9;
        for(int i=1;i<=nums[idx];i++){
            mini=min(mini,1+f(idx+i,nums,n,dp));
        }
        return dp[idx]=mini;
    }

    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,n,dp);
    }
};
