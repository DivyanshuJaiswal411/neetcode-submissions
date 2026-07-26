class Solution {
public:
    void dfs(int row,int col,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& vis,vector<int>& delrow,vector<int>& delcol){
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && grid[newrow][newcol]=='1' && !vis[newrow][newcol]){
                dfs(newrow,newcol,n,m,grid,vis,delrow,delcol);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<int> delrow={0,-1,0,1};
        vector<int> delcol={1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,n,m,grid,vis,delrow,delcol);
                } 
            }
        }
        return cnt;
    }
};
