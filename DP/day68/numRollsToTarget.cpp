class Solution {
public:
    int mod = 1e9 + 7;
    
    int memo(int n, int k, int target, vector<vector<int>> &dp) {
        if (n == 0) return target == 0 ? 1 : 0;
        if (target <= 0) return 0;
        if (dp[n][target] != -1) return dp[n][target];
        
        int ways = 0;
        for (int i = 1; i <= k; ++i) {
            ways = (ways + memo(n - 1, k, target - i, dp)) % mod;
        }
        return dp[n][target] = ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        dp[0][0] = 1;  
        
        for (int dice = 1; dice <= n; ++dice) {
            for (int t = 1; t <= target; ++t) {
                int ways = 0;
                for (int face = 1; face <= k; ++face) {
                    if (t >= face) {
                        ways = (ways + dp[dice - 1][t - face]) % mod;
                    }
                }
                dp[dice][t] = ways;
            }
        }
        return dp[n][target];
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        // return memo(n, k, target, dp);
        return tabu(n, k, target, dp);
    }
};
