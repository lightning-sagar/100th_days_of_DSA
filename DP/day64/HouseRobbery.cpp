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

    //from let to right

public:
    int tabo(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,-1);
        dp[n-1] = nums[n-1];
        for(int i = n-2;i>=0;i++){
            int temp = 0;
            if(i+2<n){
                temp = dp[i+2];
            }
            int include = nums[i] + temp;
            int exclude = 0 + dp[i+1];
            dp[i] = max(include,exclude);
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
    // return recusive(nums,0,nums.size()-1);   
    vector<
    }
};