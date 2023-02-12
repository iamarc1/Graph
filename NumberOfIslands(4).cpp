class Solution {
public:
   //time-> o(n*m*9)
  // space -> o(n*m)
    bool ok(int x, int y,int n,int m) { return x >= 0 && y >= 0 && x < n && y < m; }
    void bfs(int row,int col,vector<vector<char>> &grid, vector<vector<bool>> &vis){
        vis[row][col]=1;
        queue<pair<int,int>> q;
        q.push({row,col});
        int n=grid.size(),m=grid[0].size();
        while(!q.empty()){
            int nrow=q.front().first;
            int ncol=q.front().second;
            q.pop();
        for(int d=0; d<4; d++){
            int nr=nrow + (d==2) - (d==0);
            int nc= ncol + (d==3) - (d==1);
            if(ok(nr,nc,n,m) && grid[nr][nc]=='1' && !vis[nr][nc]){
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int ans=0;
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    ans++;
                    bfs(row,col,grid,vis);
                }
            }
        }
        return ans;
    }
};
