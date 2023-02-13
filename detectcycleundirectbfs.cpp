#include<bits/stdc++.h>
using namespace std;
bool detect(int src,vector<int> adj[],vector<int> &vis){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto &i: adj[node]){
            if(!vis[i]){
                vis[i]=1;
                q.push({i,node});
            }
            else if(parent!=i){
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int n, vector<int> adj[]){
    vector<int> vis(n+1,0);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(detect(i,adj,vis)) return true;
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