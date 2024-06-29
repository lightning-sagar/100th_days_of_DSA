class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;
        
        vector<list<int>> adj(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        vector<bool> visited(n, false);
        q.push(source);
        visited[source] = true;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (auto it : adj[node]) {
                if (!visited[it]) {
                    if (it == destination) return true;  
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
        
        return visited[destination];
    }
};
