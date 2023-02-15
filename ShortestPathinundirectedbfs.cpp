class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto &it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(N);
        for(int i=0; i<N; i++){
            dist[i]=1e9;
        }
        queue<int> q;
        q.push(src);
        dist[src]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto &i: adj[node]){
                if(dist[node]+1<dist[i]){
                    dist[i]=dist[node]+1;
                    q.push(i);
                }
            }
        }
        vector<int> ans;
        for(auto &i: dist){
            if(i==1e9) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
