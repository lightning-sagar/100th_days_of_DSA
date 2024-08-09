class Solution {
    //from recursive
    int recusive(vector<int>& nums,int i){
        int n = nums.size();
        if(n==1) return nums[0];
        if(i>=n) return 0;
        int include = nums[i] + recusive(nums,i+2);
        int exclude = 0 + recusive(nums,i+1);
        return max(include,exclude);
    }

    //from right to left
    int RtoL(vector<int>& nums,vector<int>& dp,int i){
        if (i < 0) return 0;
        if(dp[i]!=-1){
            return dp[i];
        }
        int include = nums[i] + RtoL(nums,dp,i-2);
        int exclude = 0 + RtoL(nums,dp,i-1);
        dp[i] = max(include,exclude);
        return dp[i];
    }
    //tubo 
    int tubo(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i--){
            int temp =0;
            if(i+2<n){
                temp = dp[i+2];
            }
            int include = temp + nums[i];
            int exclude = 0 + dp[i+1];
            dp[i] = max(include,exclude);
        }
        return dp[0];
    }
    //space-opti
    int spc(vector<int>& nums){
        int n = nums.size();
        int prev = nums[n-1];
        int next=0;
        int curr;
        for(int i=n-1;i>=0;i--){
            int temp =0;
            if(i+2<n){
                temp = next;
            }
            int include = temp + nums[i];
            int exclude = 0 + prev;
            curr = max(include,exclude);
            next = prev;
            prev = curr;
        }
        return prev;
    }
public:
    
    
    
    int rob(vector<int>& nums) {
    // return recusive(nums,0,nums.size()-1);
        // int n = nums.size();   
        // vector<int> dp(n,-1);
        return spc(nums);
    }
};