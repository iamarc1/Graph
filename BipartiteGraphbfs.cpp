class Solution {
public:
    bool bfs(int src,vector<int> adj[],vector<int> &color){
        queue<int> q;
        q.push(src);
        color[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &i: adj[node]){
                if(color[i]==-1){
                    color[i]=!color[node];
                    q.push(i);
                }
                else if(color[i]==color[node]){
                    return false;
                }
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
                if(bfs(i,adj,color)==false) return false;
            }
        }
        return true;
    }
};
