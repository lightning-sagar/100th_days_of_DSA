class Solution {
public:
int dp[1001];
#define mod 1000000007

    int solve(int i, int delay, int forget, int n) {
        
        if(i +delay > n) return 1;

        if(dp[i] != -1) return dp[i];
        
        int res = 1;
        
        for(int ind = i+delay; ind <= min(n, i+forget); ind++) {
            if(ind == i+forget){
                res -= 1;
                break;
            }
            res = (res%mod + solve(ind, delay, forget, n) % mod) % mod;
        }

        return dp[i] = res;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        memset(dp, -1, sizeof(dp));
        return solve(1, delay, forget, n);
    }
};