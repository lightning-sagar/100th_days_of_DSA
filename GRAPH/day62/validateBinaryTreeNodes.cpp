class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& indegree) {
        for (int nxt : adj[node]) {
            indegree[nxt]--;
            if (indegree[nxt] == 0) {
                if (dfs(nxt, adj, indegree)) return true;
            }
        }
        return false;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) adj[i].push_back(leftChild[i]);
            if (rightChild[i] != -1) adj[i].push_back(rightChild[i]);
        }
        
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int node : adj[i]) {
                indegree[node]++;
            }
        }
        
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (root != -1) return false;
                root = i;
            }
        }
        if (root == -1) return false;
        if (adj[root].size() > 1) return false;
        return dfs(root, adj, indegree);
    }
};