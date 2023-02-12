class Solution {
public:
    bool ok(int x, int y,int n,int m) { return x >= 0 && y >= 0 && x < n && y < m; }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int fresh=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==2){
                q.push({{i,j},0});
                vis[i][j]=2;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        int time=0;
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int tm=q.front().second;
            time=max(tm,time);
            q.pop();
            for(int d=0; d<4; d++){
                int nr=row+(d==2)-(d==0);
                int nc=col+(d==3)-(d==1);
                if(ok(nr,nc,n,m) && grid[nr][nc]==1 && vis[nr][nc]!=2){
                    vis[nr][nc]=2;
                    q.push({{nr,nc},tm+1});
                    fresh--;
                }
            }
        }
    return (fresh==0)?time:-1;
    }
};
