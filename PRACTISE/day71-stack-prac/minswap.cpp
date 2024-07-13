class Solution {
public:
    int minSwaps(string s) {
        if(s.size() == 0) return 0;
        stack<char> st;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '['){
                st.push('[');
            }
            else{
                if(!st.empty() && st.top() == '['){
                    st.pop();
                }
                else{
                    st.push(']');
                }
            }
        }

        int ans = st.size();  
        // cout<<ans;    
         
        //if ans is odd then st.size()/2-1
        return ceil(ans/4.0) ;
        
    }
};