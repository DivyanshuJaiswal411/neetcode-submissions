class Solution {
public:
    // int f(int ind1,int ind2,string s,string t,vector<vector<int>>& dp){
    //     if(ind1<0 || ind2<0) return 0;
    //     if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
    //     if(s[ind1]==t[ind2]){
    //         return dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
    //     }
    //     return dp[ind1][ind2]=max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
    // }

    pair<int,int> f(int left,int right,int n,string s){
        int len=0;
        while(left>=0 && right<n && s[left]==s[right]){
            len=max(len,right-left+1);
            left--;
            right++;
        }
        return {len,left+1};
    }

    string longestPalindrome(string s) {
        int n=s.size();
        int maxi=0;
        int start=-1;
        for(int i=0;i<n;i++){
            auto odd=f(i,i,n,s);
            if(odd.first>maxi){
                maxi=odd.first;
                start=odd.second;
            }
            if(i!=n-1){
                auto even=f(i,i+1,n,s);
                if(even.first>maxi){
                    maxi=even.first;
                    start=even.second;
                }
            }
        }
        return s.substr(start,maxi);
    }
};
