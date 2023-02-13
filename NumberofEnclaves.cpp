class Solution {
public:
    bool ok(int x,int y,int n,int m) { return x>=0 && x<n && y>=0 && y<m;}
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        queue<pair<int,int>> q;
        for(int i=0; i<m; i++){
            if(!vis[0][i] && grid[0][i]==1){
                q.push({0,i});
            }
            if(!vis[n-1][i] && grid[n-1][i]==1){
                q.push({n-1,i});
            }
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && grid[i][0]==1){
                q.push({i,0});
            }
            if(!vis[i][m-1] && grid[i][m-1]==1){
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
                if(ok(nr,nc,n,m) && !vis[nr][nc] && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};
