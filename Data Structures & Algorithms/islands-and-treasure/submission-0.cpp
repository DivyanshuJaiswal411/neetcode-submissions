class Solution {
public:
    int INF=2147483647;
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    pq.push({0,{i,j}});
                }
            }
        }
        vector<int> delrow={0,-1,0,1};
        vector<int> delcol={1,0,-1,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int row=it.second.first;
            int col=it.second.second;
            int dis=it.first;
            for(int i=0;i<4;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && grid[newrow][newcol]!=-1 && 1+dis<grid[newrow][newcol]){
                    grid[newrow][newcol]=1+dis;
                    pq.push({1+dis,{newrow,newcol}});
                }
            }
        }
    }
};
