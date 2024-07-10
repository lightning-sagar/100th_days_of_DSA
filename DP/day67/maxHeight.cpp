class Solution {
    bool check(vector<int> &a, vector<int> &b) {
        if(a[0] > b[0] && a[1] > b[1] && a[2] > b[2]) {
            return true;
        }
        return false;
    }
    int tab(vector<vector<int>>& cuboids) {
        int n = cuboids.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int curr = nums.size()-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--) {
                int include = 0;
                if(prev == -1 || check(cuboids[curr], cuboids[prev]) ) {
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0+dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
public:
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &c:cuboids) {
            sort(c.begin(), c.end());
        }
        sort(cuboids.begin(), cuboids.end());
        return tab(cuboids);
    }
};