class Solution {
public:
    bool ok(int x, int y,int n,int m) { return x >= 0 && y >= 0 && x < n && y < m; }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // o(n*m*4) space o(n*m)
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        vector<vector<int>> ans=vis;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int step=q.front().second;
            q.pop();
            ans[row][col]=step;
            for(int d=0; d<4; d++){
                int nr=row+(d==2)-(d==0);
                int nc=col+(d==3)-(d==1);
                if(ok(nr,nc,n,m) && vis[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},step+1});
                }
            }
        }
        return ans;
    }
};
