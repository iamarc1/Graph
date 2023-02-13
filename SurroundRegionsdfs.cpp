class Solution {
public:
    // time - o(n*m)+ o(n*m*4) + boundary loops == o(n*m)
    bool ok(int x,int y,int n,int m) { return x>=0 && x<n && y>=0 && y<m; }
    void dfs(int row,int col,vector<vector<char>> &grid,vector<vector<bool>> &vis){
        vis[row][col]=1;
        int n=grid.size(),m=grid[0].size();
        for(int d=0; d<4; d++){
            int nr=row+(d==2)-(d==0);
            int nc=col+(d==3)-(d==1);
            if(ok(nr,nc,n,m) && !vis[nr][nc] && grid[nr][nc]=='O'){
                dfs(nr,nc,grid,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0; i<m; i++){
        if(!vis[0][i] && board[0][i]=='O'){
            dfs(0,i,board,vis);
        }
        if(!vis[n-1][i] && board[n-1][i]=='O'){
            dfs(n-1,i,board,vis);
        }
        }
        for(int i=0; i<n; i++){
        if(!vis[i][0] && board[i][0]=='O'){
            dfs(i,0,board,vis);
        }
        if(!vis[i][m-1] && board[i][m-1]=='O'){
            dfs(i,m-1,board,vis);
        }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
      
    }
};
