class Solution {
public:
    // recursively
    int recursion(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        
        int mini = INT_MAX;
        
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                int ans = recursion(coins, amount - coins[i]);
                
                if (ans != -1) {
                    mini = min(mini, ans + 1);
                }
            }
        }
        
        if (mini == INT_MAX) return -1;
        
        return mini;
    }
    // memoization
    int meom(vetor<int>& coins, int amount, vector<int>& dp) {
        if (amount == 0) return 0;
        if(dp[amount] != -1) return dp[amount];
        
        int mini = INT_MAX;
        
        for (int i = 0; i < coins.size(); i++) {
            if (amount - coins[i] >= 0) {
                int ans = meom(coins, amount - coins[i], dp);
                
                if (ans != -1) {
                    mini = min(mini, ans + 1);
                }
            }
        }
        
        if (mini == INT_MAX) return -1;
        
        return dp[amount] = mini;
    }

    // tabulation
    int tabu(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            int mini = INT_MAX;
            for (int j = 0; j < coins.size(); j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    mini = min(mini, dp[i - coins[j]] + 1);
                }
            }
            dp[i] = mini;
        }
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount) {
        // return recursion(coins, amount);
        // vector<int> dp(amount + 1, -1);
        // return meom(coins, amount, dp);
        return tabu(coins, amount);
    }
};
