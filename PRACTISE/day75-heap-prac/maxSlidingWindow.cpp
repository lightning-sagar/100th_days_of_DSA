class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& num, int k) {
       deque<int> dq;
       vector<int> ans;
       for(int i=0;i<k;i++){
        while(!dq.empty()&&num[i]>=num[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
       } 
       ans.push_back(num[dq.front()]);
       for(int i=k;i<num.size();i++){
        if (i - dq.front() >= k) {
            dq.pop_front();
        }
        while(!dq.empty()&&num[i]>=num[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
        ans.push_back(num[dq.front()]);
       }
       return ans;
    }
};