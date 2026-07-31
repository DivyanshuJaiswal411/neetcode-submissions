class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int it:nums) pq.push(it);
        int ans=-1;
        for(int i=0;i<k;i++){
            ans=pq.top();
            pq.pop();
        }
        return ans;
    }
};
