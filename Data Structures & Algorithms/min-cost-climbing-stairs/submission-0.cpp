class Solution {
public:
    int f(int idx,vector<int>& cost,vector<int>& dp){
        if(idx==0 || idx==1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int onestep=f(idx-1,cost,dp)+cost[idx-1];
        int twostep=f(idx-2,cost,dp)+cost[idx-2];
        return dp[idx]=min(onestep,twostep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n+1,-1);
        return f(n,cost,dp);
    }
};
