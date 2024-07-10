class Solution {
public:
    // Recursion
    int rec(string a, string b, int i, int j) {
        if (i == a.length()) {
            return b.length() - j;  
        }
        if (j == b.length()) {
            return a.length() - i;  
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = rec(a, b, i + 1, j + 1);   
        } else {
            int insert = 1 + rec(a, b, i, j + 1);   
            int remove = 1 + rec(a, b, i + 1, j);   
            int replace = 1 + rec(a, b, i + 1, j + 1);   
            ans = min(insert, min(remove, replace));
        }
        return ans;
    }

    // Memoization
    int memo(string a, string b, int i, int j, vector<vector<int>> &dp) {
        if (i == a.length()) {
            return b.length() - j;   
        }
        if (j == b.length()) {
            return a.length() - i;   
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if (a[i] == b[j]) {
            ans = memo(a, b, i + 1, j + 1, dp);   
        } else {
            int insert = 1 + memo(a, b, i, j + 1, dp);   
            int remove = 1 + memo(a, b, i + 1, j, dp);   
            int replace = 1 + memo(a, b, i + 1, j + 1, dp);   
            ans = min(insert, min(remove, replace));
        }
        return dp[i][j] = ans;
    }

    // Tabulation
    int tabu(string a, string b) {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));

        for (int j = 0; j <= b.length(); j++) {
            dp[0][j] = j;   
        }
        for (int i = 0; i <= a.length(); i++) {
            dp[i][0] = i;   
        }

        for (int i = 1; i <= a.length(); i++) {
            for (int j = 1; j <= b.length(); j++) {
                if (a[i - 1] == b[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];   
                } else {
                    int insert = dp[i][j - 1];
                    int remove = dp[i - 1][j];
                    int replace = dp[i - 1][j - 1];
                    dp[i][j] = 1 + min(insert, min(remove, replace));
                }
            }
        }

        return dp[a.length()][b.length()];
    }

    // Space Optimization
    int spaceOp(string a, string b) {
        vector<int> prev(b.length() + 1, 0), cur(b.length() + 1, 0);

        for (int j = 0; j <= b.length(); j++) {
            prev[j] = j;   
        }

        for (int i = 1; i <= a.length(); i++) {
            cur[0] = i;  
            for (int j = 1; j <= b.length(); j++) {
                if (a[i - 1] == b[j - 1]) {
                    cur[j] = prev[j - 1];   
                } else {
                    int insert = cur[j - 1];
                    int remove = prev[j];
                    int replace = prev[j - 1];
                    cur[j] = 1 + min(insert, min(remove, replace));
                }
            }
            prev = cur;  
        }

        return prev[b.length()];
    }

public:
    int minDistance(string word1, string word2) {
        // return rec(word1, word2, 0, 0);
        // vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        // return memo(word1, word2, 0, 0, dp);
        // return tabu(word1, word2);
        return spaceOp(word1, word2);
    }
};
