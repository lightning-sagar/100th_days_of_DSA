class Solution {
public:
    void solve(vector<int>& candidates, int target, int index, vector<vector<int>>& ans, vector<int>& v) {
        if (target == 0) {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) continue; 
            if (candidates[i] > target) break;  
            v.push_back(candidates[i]);
            solve(candidates, target - candidates[i], i + 1, ans, v); 
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(candidates, target, 0, ans, v);  
        return ans;     
    }
};
