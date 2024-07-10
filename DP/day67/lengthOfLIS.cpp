class Solution {
    //using recursion
    // int rec(vector<int>& nums, int curr, int prev) {
    //     if(curr >= nums.size() ) return 0;
    //     int include = 0;
    //     if(prev == -1 || nums[curr]>nums[prev]) {
    //         include = 1 + rec(nums, curr+1, curr);
    //     }
    //     int exclude = 0+rec(nums, curr+1, prev);
    //     return max(include, exclude);
    // }

    // using memoization
    // int memo(vector<vector<int>>& dp, vector<int>& nums, int curr, int prev) {
    //     if(curr >= nums.size() ) return 0;
    //     if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
    //     int include = 0;
    //     if(prev == -1 || nums[curr]>nums[prev]) {
    //         include = 1 + memo(dp,nums, curr+1, curr);
    //     }
    //     int exclude = 0+memo(dp,nums, curr+1, prev);
    //     return dp[curr][prev+1] = max(include, exclude);
    // }
    //tabulation
    int tab(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int curr = nums.size()-1; curr>=0; curr--) {
            for(int prev = curr-1; prev>=-1; prev--) {
                int include = 0;
                if(prev == -1 || nums[curr]>nums[prev]) {
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0+dp[curr+1][prev+1];
                dp[curr][prev+1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }
    //space optimization
    int spaceOpt(vector<int>& nums) {
        int n = nums.size();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int currIndex = n - 1; currIndex >= 0; currIndex--) {
            for (int prevIndex = currIndex - 1; prevIndex >= -1; prevIndex--) {
                int include = 0;
                if (prevIndex == -1 || nums[currIndex] > nums[prevIndex]) {
                    include = 1 + prev[currIndex + 1];
                }
                int exclude = prev[prevIndex + 1];
                curr[prevIndex + 1] = max(include, exclude);
            }
            prev = curr;
        }
        return prev[0];
    }

public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // // return rec(nums, 0, -1);
        // // vector<vector<int>> dp(n, vector<int>(n+1, -1));
        // // return memo(dp, nums, 0, -1);
        // // return tab(nums);
        // return spaceOpt(nums);
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=0;i<nums.size();i++) {
            if(nums[i] > ans.back()) {
                ans.push_back(nums[i]);
            }
            else {
                int ind = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[ind] = nums[i];
            }
        }
        return ans.size();
    }
};