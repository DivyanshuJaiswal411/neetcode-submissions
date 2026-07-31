class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mpp;
        for(int it:nums){
            mpp[it]++;
        }
        priority_queue<pair<int,int>> pq;
        for(auto it:mpp){
            if(it.second>0) pq.push({it.second,it.first});
        }
        vector<int> ans;
        for(int i=0;i<k;i++){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};
