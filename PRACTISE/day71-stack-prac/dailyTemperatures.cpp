    class Solution {
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures) {
            // compare the current element with the next element and check if the next element is greater than the current element 
            // if yes then push 1 else push 0
            vector<int> ans;
            stack<int> st;
            for(int i=0;i<temperatures.size();i++){
                while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                    ans[st.top()]=i-st.top();
                    st.pop();
                }
                st.push(i);
            }
            while(!st.empty()){
                ans[st.top()]=0;
                st.pop();
            }
            return ans;
        }
    };