long long countWays(int n, int k){
        // code here
        if(k==1) return k;
        if(k==2) return (k+k*(k-1));
    
        long long ans = countWays(n-1,k)countWays(n-2,k);
        
        return ans*(k-1);
    }

//space optimization
long long countWays(int n, int k) {
    int prev1 = k;
    int prev2 = k*(k-1);

    for(int i=3;i<=n;i++){
        int curr = (prev1+prev2)*(k-1);
        prev1 = prev2;
        prev2 = curr;
    }
    return prev2;
}

//using memoization
int solve(int n,int k,vector<int>&dp){
    if(k==1) return k;
    if(k==2) return (k+k*(k-1));
    if(dp[n]!=-1) return dp[n];
    int ans = (solve(n-1,k,dp) + solve(n-2,k,dp)) * (k-1);
    return dp[n]=ans;
}

//tabulation
int solve(int n,int k){
    vector<int>dp(n+1,-1);
    dp[1]=k;
    dp[2]=k*k;
    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])*(k-1);
    }
    return dp[n];
}   