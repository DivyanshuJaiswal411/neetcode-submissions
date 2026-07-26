class Solution {
public:
    // void f(int row,int col,int m,int n,vector<vector<char>>& board,vector<int>& delrow,vector<int>& delcol){
    //     board[row][col]="X";
    //     for(int i=0;i<4;i++){
    //         int newrow=row+delrow[i];
    //         int newcol=col+delcol[i];
    //         if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && board[newrow][newcol]=="O"){
    //             f(newrow,newcol,m,n,board,delrow,delcol);
    //         }
    //     }
    // }

    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++){
            if(board[i][0]=='O') q.push({i,0});
            if(board[i][n-1]=='O') q.push({i,n-1});
        }
        for(int i=1;i<n-1;i++){
            if(board[0][i]=='O') q.push({0,i});
            if(board[m-1][i]=='O') q.push({m-1,i});
        }
        vector<int> delrow={0,-1,0,1};
        vector<int> delcol={1,0,-1,0};
        vector<vector<int>> vis(m,vector<int>(n,0));
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            vis[row][col]=1;
            for(int i=0;i<4;i++){
                int newrow=row+delrow[i];
                int newcol=col+delcol[i];
                if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && !vis[newrow][newcol] && board[newrow][newcol]=='O'){
                    q.push({newrow,newcol});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && !vis[i][j]) board[i][j]='X';
            }
        }
    }
};
