void dfs(int src,vector<int> adj[], vector<bool> &vis,stack<int> &st){
	    vis[src]=1;
	    for(auto &i: adj[src]){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    st.push(src);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<bool> vis(V,0);
	    stack<int> st;
	    for(int i=0; i<V; i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
