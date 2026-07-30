class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> st;
        for(int i=0;i<k;i++){
            st.insert(nums[i]);
        }
        vector<int> ans;
        ans.push_back(*st.rbegin());
        int r=k;
        int l=0;
        while(r<n){
            st.erase(st.find(nums[l]));
            st.insert(nums[r]);
            ans.push_back(*st.rbegin());
            l++;
            r++;
        }
        return ans;
    }
};
