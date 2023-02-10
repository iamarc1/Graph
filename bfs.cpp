#include<bits/stdc++.h>
using namespace std;
//space complexity-> O(n)
// time complexity-> O(n+2e)
vector<int> bfs(int n,vector<int> adj[]){
    vector<bool> vis(n+1,0);
    vis[0]=1;
    queue<int> q;
    q.push(0);
    vector<int> trav;
    while(!q.empty()){ //o(n) for all nodes
        int node=q.front();
        q.pop();
        trav.push_back(node);
        for(auto &i: adj[node]){ // o(2e) for undirected for total degrees
            if(!vis[i]){
                vis[i]=1;
                q.push(i);
            }
        }
    }
    return trav;
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
    vector<int> ans=bfs(n,adj);
    for(auto &i: ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}