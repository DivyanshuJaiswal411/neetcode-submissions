class Solution {
public:
    int f(int ind,string s,vector<int>& dp){
        int n=s.size();
        if(ind==n) return 1;
        if(s[ind]=='0') return 0;
        if(dp[ind]!=-1) return dp[ind];
        int ans=f(ind+1,s,dp);
        if(ind+1<n){
            int num=(s[ind]-'0')*10+(s[ind+1]-'0');
            if(num>=10 && num<=26) ans+=f(ind+2,s,dp);
        }
        return dp[ind]=ans;
    }

    int numDecodings(string s) {
        int n=s.size();
        vector<int> dp(n,-1);
        int ans=f(0,s,dp);
        return ans;
    }
};
