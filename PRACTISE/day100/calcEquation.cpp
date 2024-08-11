class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;
        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];

        }   

        for (int i = 0; i < equations.size(); i++) {
            graph[equations[i][1]][equations[i][0]] = 1 / values[i];

        }

        vector<double> ans;

        for (int i = 0; i < queries.size(); i++) {
            if (graph.find(queries[i][0]) == graph.end() || graph.find(queries[i][1]) == graph.end()) {
                ans.push_back(-1.0);
            } else if (queries[i][0] == queries[i][1]) {
                ans.push_back(1.0);
            } else {
                if (graph[queries[i][0]].find(queries[i][1]) != graph[queries[i][0]].end()) {
                    ans.push_back(graph[queries[i][0]][queries[i][1]]);
                } else {
                    ans.push_back(dfs(queries[i][0], queries[i][1], graph, 1.0));
                }
            }
        }

        return ans;
    }
};