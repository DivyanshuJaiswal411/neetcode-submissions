class Solution {
public:
    void dfs(int row,int col,int n,int m,int& cnt,vector<vector<int>>& grid,vector<vector<int>>& vis,vector<int>& delrow,vector<int>& delcol){
        vis[row][col]=1;
        cnt++;
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !vis[newrow][newcol] && grid[newrow][newcol]==1){
                dfs(newrow,newcol,n,m,cnt,grid,vis,delrow,delcol);
            }
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> delrow={0,-1,0,1};
        vector<int> delcol={1,0,-1,0};
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    int cnt=0;
                    dfs(i,j,n,m,cnt,grid,vis,delrow,delcol);
                    maxi=max(maxi,cnt);
                }
            }
        }
        return maxi;
    }
};
