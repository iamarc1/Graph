class Solution {
public:
    bool ok(int x, int y,int n,int m) { return x >= 0 && y >= 0 && x < n && y < m; }
    void dfs(int row,int col, vector<vector<int>> &grid,int old,int color,vector<vector<int>> &ans){
        ans[row][col]=color;
        int n=grid.size(),m=grid[0].size();
        for(int d=0; d<4; d++){
            int nr=row+(d==2)-(d==0);
            int nc=col+(d==3)-(d==1);
            if(ok(nr,nc,n,m) && grid[nr][nc]==old && ans[nr][nc]!=color){
                dfs(nr,nc,grid,old,color,ans);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old=image[sr][sc];
        vector<vector<int>> ans=image;
        dfs(sr,sc,image,old,color,ans);
        return ans;
    }
};
