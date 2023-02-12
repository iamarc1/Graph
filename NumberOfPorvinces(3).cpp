class Solution {
public:
    void dfs(int start,vector<int> adj[],vector<int> &vis){
        vis[start]=1;
        for(auto &i: adj[start]){
            if(!vis[i]){
                dfs(i,adj,vis);
            }
        }
    }
    //space--> o(n) 
    // time--> o(n) + o(n+2e) har ek pe dfs can go till components
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int provinces=0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                provinces++;
                dfs(i,adj,vis);
            }
        }
        return provinces;
    }
};
