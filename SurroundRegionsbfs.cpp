class Solution {
public:
    // time - o(n*m)+ o(n*m*4) + boundary loops == o(n*m)
    bool ok(int x,int y,int n,int m) { return x>=0 && x<n && y>=0 && y<m; }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size(),m=board[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
        if(!vis[0][i] && board[0][i]=='O'){
            q.push({0,i});
        }
        if(!vis[n-1][i] && board[n-1][i]=='O'){
            q.push({n-1,i});
        }
        }
        for(int i=0; i<n; i++){
        if(!vis[i][0] && board[i][0]=='O'){
           q.push({i,0});
        }
        if(!vis[i][m-1] && board[i][m-1]=='O'){
           q.push({i,m-1});
        }
        }
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            vis[row][col]=1;
            for(int d=0; d<4; d++){
                int nr=row+(d==2)-(d==0);
                int nc=col+(d==3)-(d==1);
                if(ok(nr,nc,n,m) && !vis[nr][nc] && board[nr][nc]=='O'){
                    q.push({nr,nc});
                }
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
