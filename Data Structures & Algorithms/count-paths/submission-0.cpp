class Solution {
public:
    int f(int x,int y,int m,int n,vector<vector<int>>& dp){
        if(x<0 || y<0) return 0;
        if(x==0 && y==0) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        int up=f(x-1,y,m,n,dp);
        int left=f(x,y-1,m,n,dp);
        return dp[x][y]=up+left;
    }   

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(m-1,n-1,m,n,dp);
    }
};
