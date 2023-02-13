#include<bits/stdc++.h>
using namespace std;
bool dfsdetect(int src,int parent,vector<int> adj[],vector<int> &vis){
    vis[src]=1;
    for(auto &i: adj[src]){
        if(!vis[i]){
        if(dfsdetect(i,src,adj,vis)) {return true; }
        }
        else if(parent!=i) {return true; }
    }
    return false;
}
bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1,0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(dfsdetect(i,-1,adj,vis)) return true;
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