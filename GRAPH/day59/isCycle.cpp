bool checkcyclichelper(int n, vector<bool>&visited, vector<bool> &dfsvisited, vector<int> adj[]){
        visited[n]=true;
        dfsvisited[n]=true;
        
        for(auto neighbour: adj[n]){
            if(!visited[neighbour]){
                if(checkcyclichelper(neighbour,visited,dfsvisited,adj)==true){
                    return true;
                }
            }else if(dfsvisited[neighbour]){
                return true;
            }
        }
        dfsvisited[n]=false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V, false);
        vector<bool>dfsvisited(V, false);
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(checkcyclichelper(i,visited,dfsvisited,adj)==true){
                    return true;
                }
            }
        }
        return false;
    }