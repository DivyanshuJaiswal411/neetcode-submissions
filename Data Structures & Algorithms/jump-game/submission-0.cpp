class Solution {
public:
    bool f(int idx,vector<int>& nums,int n,vector<bool>& dp){
        if(idx==n-1) return true;
        if(idx>=n) return false;
        for(int i=1;i<=nums[idx];i++){
            if(f(idx+i,nums,n,dp)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }

    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,-1);
        return f(0,nums,n,dp);
    }
};
