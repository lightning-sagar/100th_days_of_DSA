 void dfsUtil(int node,vector<int> adj[],vector<int> &dfs,vector<bool> &vis){
     vis[node] = true;
     dfs.push_back(node);
     for(auto nei:adj[node]){
        if(!vis[nei]){
            dfsUtil(nei,adj,dfs,vis);
        }
     }
 }
vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> dfs;
        vector<bool> visited(V,false);
        dfsUtil(0,adj,dfs,visited);
        return dfs;
    }