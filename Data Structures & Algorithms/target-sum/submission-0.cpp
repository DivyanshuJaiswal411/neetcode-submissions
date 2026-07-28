class Solution {
public:
    int f(int ind,int n,vector<int>& nums, int target,vector<vector<int>>& dp){
        if(ind==n){
            return target==0;
        }  
        if(target<-2000 || target>2000) return 0;
        if(dp[ind][target+2000]!=-1) return dp[ind][target+2000];

        int neg=f(ind+1,n,nums,target-nums[ind],dp);
        int pos=f(ind+1,n,nums,target+nums[ind],dp);
        return dp[ind][target+2000]=neg+pos;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(4001,-1));
        return f(0,n,nums,target,dp);
    }
};
