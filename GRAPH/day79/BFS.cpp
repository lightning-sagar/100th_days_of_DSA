vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    Code here
    queue<int> q;
    vector<int> bfs;
    vector<bool> visited(V,false);
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node]){
            if(!visited[it]){
                q.push(it);
                visited[it]=true;
            }
        }
    }
    return bfs;
 
    }