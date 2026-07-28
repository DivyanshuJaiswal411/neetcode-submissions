class Solution {
public:
    // bool f(int ind,vector<int>& nums,int target,vector<vector<int>>& dp){
    //     if(target==0) return true;
    //     if(ind==n-1){
    //         return nums[ind]==target;
    //     }
    //     if(dp[ind][target]!=-1) return dp[ind][target];
    //     bool not_take=f(ind-1,nums,target);
    //     bool take=false;
    //     if(nums[ind]<=target){
    //         take=f(ind-1,nums,target-nums[ind]);
    //     }
    //     dp[ind][target]=take | not_take;
    // }

    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=0;
        for(int it:nums) total+=it;
        if(total%2!=0) return false;
        int target=total/2;
        vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(nums[0]<=target) dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool not_take=dp[i-1][j];
                bool take=false;
                if(nums[i]<=j){
                    take=dp[i-1][j-nums[i]];
                }
                dp[i][j]=take || not_take;
            }
        }
        return dp[n-1][target];
    }
};
