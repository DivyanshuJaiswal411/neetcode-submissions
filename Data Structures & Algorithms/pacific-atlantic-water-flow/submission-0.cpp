class Solution {
public:
    void f(int row,int col,int n,int m,vector<vector<int>>& ocean,vector<vector<int>>& heights,vector<int>& delrow,vector<int>& delcol){
        ocean[row][col]=1;
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && !ocean[newrow][newcol] && heights[newrow][newcol]>=heights[row][col]){
                f(newrow,newcol,n,m,ocean,heights,delrow,delcol);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>> ans;
        vector<vector<int>> pacific(n,vector<int>(m,0));
        vector<vector<int>> atlantic(n,vector<int>(m,0));
        vector<int> delrow={0,-1,0,1};
        vector<int> delcol={1,0,-1,0};
        for(int i=0;i<n;i++){
            f(i,0,n,m,pacific,heights,delrow,delcol);
            f(i,m-1,n,m,atlantic,heights,delrow,delcol);
        }
        for(int i=0;i<m;i++){
            f(0,i,n,m,pacific,heights,delrow,delcol);
            f(n-1,i,n,m,atlantic,heights,delrow,delcol);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atlantic[i][j]==1 && pacific[i][j]==1) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
