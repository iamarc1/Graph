class Solution {
  public:
     void dfstopo(int node,vector<pair<int,int>> adj[],vector<bool> &vis,stack<int> &st){
         vis[node]=1;
         for(auto &i: adj[node]){
             if(!vis[i.first]){
                 dfstopo(i.first,adj,vis,st);
             }
         }
         st.push(node);
     }
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0; i<M; i++){
            int from=edges[i][0],to=edges[i][1],w=edges[i][2];
            adj[from].push_back({to,w});
        }
        
        stack<int> st;
        vector<bool> vis(N,0);
        for(int i=0; i<N; i++){
            if(!vis[i]){
                dfstopo(i,adj,vis,st);
            }
        }
        
        vector<int> dist(N);
        for(int i=0; i<N; i++) dist[i]=1e9;
        dist[0]=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            for(auto &i: adj[node]){
                int v=i.first,d=i.second;
                if(dist[node]+d<dist[v]){
                    dist[v]=dist[node]+d;
                }
            }
        }
        for(auto &i: dist){
            if(i==1e9){
                i=-1;
            }
        }
        return dist;
    }
};
