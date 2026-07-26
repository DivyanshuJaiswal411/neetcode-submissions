class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    pq.push({0,{i,j}});
                }
            }
        }
        vector<int> delrow={0,-1,0,1};
        vector<int> delcol={1,0,-1,0};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            maxi=max(maxi,time);
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]==1){
                    grid[newrow][newcol]=2;
                    pq.push({time+1,{newrow,newcol}});
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return maxi;
    }
};
