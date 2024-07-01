class Solution {
public:
    unordered_map<int, list<int>> adj; 
    vector<int> order; 

    bool dfs(int node, vector<bool> &visited, vector<bool> &recStack) {
        visited[node] = true;
        recStack[node] = true;
        for (auto nei : adj[node]) {
            if (!visited[nei]) { 
                if (dfs(nei, visited, recStack)) return true;
            }
            else if (recStack[nei]) return true;
        }
        recStack[node] = false;
        order.push_back(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Create adj list
        for (int i = 0; i < prerequisites.size(); i++) {
            int u = prerequisites[i][1];  
            int v = prerequisites[i][0];
            adj[u].push_back(v);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                if (dfs(i, visited, recStack)) return {};
            }
        }
        reverse(order.begin(), order.end());
        return order;
    }
};
