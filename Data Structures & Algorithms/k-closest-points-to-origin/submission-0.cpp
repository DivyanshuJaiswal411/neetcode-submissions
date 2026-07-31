class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>,vector<pair<int,vector<int>>>,greater<pair<int,vector<int>>>> pq;
        for(auto it:points){
            int dist=it[0]*it[0]+it[1]*it[1];
            pq.push({dist,it});
        }
        vector<vector<int>> ans;
        for(int i=0;i<k;i++){
            auto it=pq.top();
            pq.pop();
            ans.push_back(it.second);
        }
        return ans;
    }
};
