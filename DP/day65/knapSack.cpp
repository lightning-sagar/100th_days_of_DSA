//space opt
int knapSack(int W, int wt[], int val[], int n) 
    { 
            
        vector<int>prev(W+1,0) , cur(W+1,0);
       
       // Step 1: Base cases
       for(int i=wt[0]; i<=W; i++) prev[i] = val[0];
       
       // Step 2: Represent all the states
       for(int ind=1; ind<n; ind++){
           for(int w=0; w<=W; w++){
               
               // Step 3: Copy recursion
               int notTake = 0 + prev[w];
               int take = INT_MIN;
               if(wt[ind] <= w) take = val[ind] + prev[w - wt[ind]];
               
               cur[w] = max(take, notTake);
           }
           prev=cur;
       }
       return prev[W];
    }

//Tabulation
int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        
        // Step 1: Base cases
        for(int i=wt[0]; i<=W; i++) dp[0][i] = val[0];
        
        // Step 2: Represent all the states
        for(int ind=1; ind<n; ind++){
            for(int w=0; w<=W; w++){
                
                // Step 3: Copy recursion
                int notTake = 0 + dp[ind-1][w];
                int take = INT_MIN;
                if(wt[ind] <= w) take = val[ind] + dp[ind-1][w - wt[ind]];
                
                dp[ind][w] = max(take, notTake);
            }
        }
        return dp[n-1][W];
    }
//memoization
int knapSack(int W, int wt[], int val[], int n, vector<vector<int>>&dp) 
{
    if(n==0 || W==0) return 0;
    if(dp[n][W] != -1) return dp[n][W]; 
    if(wt[n-1] > W) return dp[n][W] = knapSack(W, wt, val, n-1, dp);
    return dp[n][W] = max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1, dp), knapSack(W, wt, val, n-1, dp));
}