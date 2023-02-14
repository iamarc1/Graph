#include<bits/stdc++.h>
using namespace std;
bool dfsdetect(int src,vector<int> adj[],vector<int> &vis,vector<int> &path){
    vis[src]=1;
    path[src]=1;
    for(auto &i: adj[src]){
        if(!vis[i]){
            if(dfs(i,adj,vis,path)){
                return true;
            }
        }
        else if(path[i]){
            return true;
        }
    }
    path[src]=0;
    return false;
}
bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n,0),path(n,0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(dfsdetect(i,adj,vis,path)) return true;
        }
    }
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        //adj[v].push_back(u);
    }
    bool ok=isCycle(n,adj);
    return 0;
}