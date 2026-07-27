class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> vis(n,0);
        int total_cost=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [cost,u]=pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u]=1;
            total_cost+=cost;
            for(int i=0;i<n;i++){
                if(!vis[i]){
                    int dis=abs(points[u][0]-points[i][0])+abs(points[u][1]-points[i][1]);
                    pq.push({dis,i});
                }
            }
        }
        return total_cost;
    }
};
