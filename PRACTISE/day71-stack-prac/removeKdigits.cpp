class Solution {
public:
    string removeKdigits(string num, int k) {
        //check if top is smaller than the next element if no then pop it else push it and always put the last element in the string
        stack<char> st;
        int n=num.size();
        for(int i=0;i<n;i++)
        {
            while(k>0 && !st.empty() && num[i]<st.top())
            {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        //cout
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }
        ans = ans.substr(i);

        // If ans is empty, return "0"
        return ans.empty() ? "0" : ans;
    }
};