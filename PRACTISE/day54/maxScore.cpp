class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
         std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        int i =0;
        int j =0;
        int ans =0;
        int sum =0;
        int totalsum=0;
        for(int i =0;i<cardPoints.size();i++)totalsum+=cardPoints[i];
        if(k==cardPoints.size())return totalsum;
        while(j<cardPoints.size())
        {
            sum+=cardPoints[j];
            if(j-i+1<cardPoints.size()-k)
            {
                j++;
            }   
            else{
                ans=max(ans,totalsum-sum);
                sum-=cardPoints[i];
                i++;
                j++;
            }
        }
        return ans;
    }
};