class Solution {
public:
    int f(int ind,vector<int>& nums,vector<int>& dp){
        int n=nums.size();
        if(ind==n-1) return nums[ind];
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind];
        if(ind+2<n) take+=f(ind+2,nums,dp);
        int not_take=f(ind+1,nums,dp);
        return dp[ind]=max(take,not_take);
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return f(0,nums,dp);
    }
};
