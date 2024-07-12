class Solution {
    int rec(int n){
        if(n == 0) return 0;
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            ans = min(ans, 1 + rec(n - i*i));
        }
        return ans;
    }
    int memo(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        int ans = INT_MAX;
        for(int i = 1; i*i <= n; i++){
            ans = min(ans, 1 + memo(n - i*i, dp));
        }
        return dp[n] = ans;
    }
    int tabu(int n){
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j*j <= i; j++){
                dp[i] = min(dp[i], 1 + dp[i - j*j]);
            }
        }
        return dp[n];
    }
public:
    int numSquares(int n) {
        // approach - 1
        // vector<int> dp(n+1, INT_MAX);
        // dp[0] = 0;
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j*j <= i; j++){
        //         dp[i] = min(dp[i], 1 + dp[i - j*j]);
        //     }
        // }
        // return dp[n];
        
        // approach - 2 using rec
        // return rec(n);

        // approach - 3 using memoization
        vector<int> dp(n+1, -1);
        return memo(n, dp);

        // approach - 4 using tabulation
        // return tabu(n);
    }
};