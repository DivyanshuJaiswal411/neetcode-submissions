class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int cntzero=0;
        int idx=0;
        int totalprod=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(cntzero==0) idx=i;
                cntzero++;
            }
            else{
                totalprod*=nums[i];
            }
        }
        vector<int> ans(n,0);
        if(cntzero>1){
            return ans;
        }
        else if(cntzero==1){
            ans[idx]=totalprod;
            return ans;
        }
        for(int i=0;i<n;i++){
            ans[i]=totalprod/nums[i];
        }
        return ans;
    }
};
