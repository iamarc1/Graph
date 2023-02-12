class Solution {
public:
    bool ok(int x, int y,int n,int m) { return x >= 0 && y >= 0 && x < n && y < m; }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(),m=image[0].size();
        int reqcolor=image[sr][sc];
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        vis[sr][sc]=1;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        
        while(!q.empty()){
            int nrow=q.front().first;
            int ncol=q.front().second;
            image[nrow][ncol]=color;
            q.pop();
        for(int d=0; d<4; d++){
            int nr=nrow + (d==2) - (d==0);
            int nc= ncol + (d==3) - (d==1);
            if(ok(nr,nc,n,m) && image[nr][nc]==reqcolor && !vis[nr][nc]){
                vis[nr][nc]=1;
                q.push({nr,nc});
            }
        }
        }
        return image;    
    }
};  
