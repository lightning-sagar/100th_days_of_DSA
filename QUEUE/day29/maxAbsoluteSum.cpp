class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int mxSum = INT_MIN, currPos = 0, currNeg = 0;
        for(int i=0; i<nums.size(); i++){
            currPos += nums[i];
            currNeg += nums[i];
            mxSum = max({mxSum,abs(currPos), abs(currNeg)});
            if(currPos < 0) currPos = 0;
            if(currNeg > 0) currNeg = 0;
        }
        return mxSum;
    }
};