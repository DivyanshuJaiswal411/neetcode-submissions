class Solution {
public:
    int f(int ind,int target,vector<int>& coins,vector<vector<int>>& dp){
        if(ind==0){
            return target%coins[ind]==0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take=f(ind-1,target,coins,dp);
        int take=0;
        if(coins[ind]<=target) take=f(ind,target-coins[ind],coins,dp);
        return dp[ind][target]=take+not_take;
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};
