class Solution {
public:
    bool dfs(int node,int col,vector<int> adj[],vector<int> &color){
        color[node]=col;
        for(auto &i: adj[node]){
            if(color[i]==-1){
                if(dfs(i,!col,adj,color)==false){
                    return false;
                }
            }
            else if(color[i]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        for(int i=0; i<n; i++){
            for(int j=0; j<graph[i].size(); j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> color(n,-1);
        for(int i=0; i<n; i++){
            if(color[i]==-1){
                if(dfs(i,0,adj,color)==false) return false;
            }
        }
        return true;
    }
};
