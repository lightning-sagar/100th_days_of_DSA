class Solution {
    //rec
    bool solve(vector<int> &nums,int index,int total,int currSum,int target){
        if(currSum == target) return true;
        if(currSum > target || index >= nums.size()) return false;
        int include = solve(nums,index+1,total,currSum+nums[index],target);
        int exclude = solve(nums,index+1,total,currSum,target);
        return include || exclude;
    }
    //memo
    bool memo(vector<int> &nums,int index,int total,int currSum,int target,vector<vector<int>> &dp){
        if(currSum == target) return true;
        if(currSum > target || index >= nums.size()) return false;
        if(dp[index][currSum] != -1) return dp[index][currSum];
        int include = 0;
        if(currSum+nums[index] <= target){
            include = memo(nums,index+1,total,currSum+nums[index],target,dp);
        }
        int exclude = memo(nums,index+1,total,currSum,target,dp);
        return dp[index][currSum] = include || exclude;
    }
    //tabu
    bool tabu(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;  
        }
        for(int ind = n - 1; ind >= 0; ind--) {
            for(int currSum = 0; currSum <= target; currSum++) {
                bool include = false;
                if(currSum + nums[ind] <= target) {
                    include = dp[ind + 1][currSum + nums[ind]];
                }
                bool exclude = dp[ind + 1][currSum];
                dp[ind][currSum] = include || exclude;
            }
        }
        return dp[0][0];
    }

public:
    bool canPartition(vector<int>& nums) {
        int index = 0;
        int total = 0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total & 1 ) return false;
        int target = total/2;
        
        // return solve(nums,index,total,0,target);
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        // return memo(nums,index,total,0,target,dp);
        return tabu(nums,target);
    }
};