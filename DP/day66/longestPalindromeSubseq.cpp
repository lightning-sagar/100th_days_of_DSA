class Solution {
    int rec(string a, string b, int i, int j) {
        if(a.length() == i || b.length() == j) {
            return 0;
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1+ rec(a, b, i+1, j+1);
        }
        else{
            ans = max(rec(a,b,i+1,j), rec(a,b,i,j+1));
        }
        return ans;
    }
    //memoization
    int memo(string a, string b, int i, int j, vector<vector<int>> &dp) {
        if(a.length() == i || b.length() == j) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int ans = 0;
        if(a[i] == b[j]) {
            ans = 1+ rec(a, b, i+1, j+1);
        }
        else{
            ans = max(rec(a,b,i+1,j), rec(a,b,i,j+1));
        }
        dp[i][j] = ans;
        return ans;
    }
    //tabulation
    int tabu(string a, string b) {
        int m = a.length();
        int n = b.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i-1] == b[j-1]) {  // Characters match
                    dp[i][j] = dp[i-1][j-1] + 1;
                } else {  // Characters don't match
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        return dp[m][n];
    }
    //space optimization
    int spaceOp(string a, string b) {
        int m = a.length();
        int n = b.length();
        vector<int> prev(n+1, 0), curr(n+1, 0);

        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(a[i-1] == b[j-1]) {  // Characters match
                    curr[j] = prev[j-1] + 1;
                } else {  // Characters don't match
                    curr[j] = max(prev[j], curr[j-1]);
                }
            }   
            prev = curr;
        }

        return prev[n];
    }
public:
    int longestPalindromeSubseq(string s) {
        string a = s;
        reverse(s.begin(), s.end());
        // return rec(text1, text2, 0, 0);
        // vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1, -1));
        // return memo(text1, text2, 0, 0, dp);
        // return tabu(text1, text2);
        return spaceOp(a, s); 
    }
};