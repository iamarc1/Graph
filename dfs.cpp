#include<bits/stdc++.h>
using namespace std;
//space complexity-> O(n)
// time complexity-> O(n)
void helper(int start, vector<int> adj[], vector<bool> &vis, vector<int> &ds){
    vis[start]=1;
    ds.push_back(start);
    for(auto &i: adj[start]){
        if(!vis[i]){
            helper(i,adj,vis,ds);
        }
    }
}
vector<int> dfs(int n, vector<int> adj[]){
    vector<bool> vis(n+1,0);
    int start=0;
    vector<int> ds;
    helper(start,adj,vis,ds);
    return ds;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans=dfs(n,adj);
    for(auto &i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}