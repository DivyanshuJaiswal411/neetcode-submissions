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
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> dp1(n-1,-1);
        vector<int> dp2(n-1,-1);
        vector<int> vec1;
        vector<int> vec2;
        for(int i=0;i<n;i++){
            if(i!=0) vec1.push_back(nums[i]);
            if(i!=n-1) vec2.push_back(nums[i]);
        }
        return max(f(0,vec1,dp1),f(0,vec2,dp2));
    }
};
