class Solution {
public:
    void solve(int k, int n, int index, vector<int> &temp, vector<vector<int>> &ans) {
        if(temp.size() == k && n == 0) {
            ans.push_back(temp);
            return;
        }
        if(temp.size() > k || n < 0) {
            return;
        }
        for(int i = index; i <= 9; i++) {
            temp.push_back(i);
            solve(k, n - i, i + 1, temp, ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(k, n, 1, temp, ans);
        return ans;      
    }
};