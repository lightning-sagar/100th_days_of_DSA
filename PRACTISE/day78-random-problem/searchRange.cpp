class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //using binary search
        int n=nums.size();
        int l=0,r=n-1;
        vector<int>ans(2,-1);
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans[0]=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans[1]=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};