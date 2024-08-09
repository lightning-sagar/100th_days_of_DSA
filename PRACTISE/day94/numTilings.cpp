class Solution {
public:
    int numTilings(int n) {
        if (n == 1) return 1;   
        if (n == 2) return 2;
        const int MOD = 1000000007;
        vector<long long> dp(n+1, 0);   
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3; i <= n; i++){
            dp[i] = (2 * dp[i-1] % MOD + dp[i-3] % MOD) % MOD;
        }   
        return dp[n]; 
    }
};