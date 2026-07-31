class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        set<int> st(nums.begin(),nums.end());
        int prev=nums[0];
        int maxlen=1;
        int curr=1;
        for(int it:st){
            if(it==prev+1){
                curr++;
                maxlen=max(maxlen,curr);
            }
            else{
                curr=1;
            }
            prev=it;
        }
        return maxlen;
    }
};
