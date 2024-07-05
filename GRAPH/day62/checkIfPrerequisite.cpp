class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<vector<int>> adj(n);
        for (const auto& it : pre) {
            adj[it[0]].push_back(it[1]); // Reverse the dependency direction
        }
        
        vector<vector<int>> reachable(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            vector<int> vis(n, 0);
            dfs(i, i, adj, reachable, vis);
        }
        
        vector<bool> ans;
        for (const auto& it : q) {
            int x = it[0];
            int y = it[1];
            ans.push_back(reachable[x][y]);
        }
        
        return ans;
    }
    
private:
    void dfs(int start, int node, const vector<vector<int>>& adj, vector<vector<int>>& reachable, vector<int>& vis) {
        vis[node] = 1;
        reachable[start][node] = 1;
        for (int nxt : adj[node]) {
            if (!vis[nxt]) {
                dfs(start, nxt, adj, reachable, vis);
            }
            for (int i = 0; i < reachable[nxt].size(); ++i) {
                reachable[start][i] |= reachable[nxt][i];
            }
        }
    }
};