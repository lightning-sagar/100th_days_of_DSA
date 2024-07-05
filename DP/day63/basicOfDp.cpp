//fibonacii series

//using recursion

int rec(int n){
    if(n==1||n==0) return n;

    int ans = rec(n-1)+(n-2);
    return ans;
}

//using dp top->down
int dpTtoD(int n,vector<int> &dp){
    if(n==1||n==0) return n;
    //checck if the ans is already present
    if(dp[n]!=-1) return dp[n];
    //store in dp array
    int ans = dpTtoD(n-1,dp)+dpTtoD(n-2,dp);
    return dp[n]=ans;
}
//using dp bottom->up
int dpBtoU(int n){
    vector<int> dp(n+1,-1);
    if(n ==0 || n==1) return n;
    dp[0] = 0;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1]+dp[i-2];

    }
    return dp[n];
}

//using dp space-optimization
int dpSO(int n){
    if(n ==0 || n==1) return n;

    int curr = 1;
    int prev = 0;
    int ans;
    for(int i=2;i<=n;i++){
        ans = curr+prev;;
        prev = curr;
        curr = ans;
    }
    return ans;
}