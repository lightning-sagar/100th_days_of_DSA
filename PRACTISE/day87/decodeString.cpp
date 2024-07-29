class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        stack<int> num;
        string ans;
        int n = s.size();
        int i = 0;
        while(i < n){
            if(s[i] >= '0' && s[i] <= '9'){
                int x = 0;
                while(s[i] >= '0' && s[i] <= '9'){
                    x = x*10 + (s[i] - '0');
                    i++;    
                }
                num.push(x);
            }else if(s[i] == '['){
                st.push(ans);
                ans = "";
                i++;
            }else if(s[i] == ']'){
                string temp = st.top();
                st.pop();
                int x = num.top();
                num.pop();
                while(x--){
                    temp += ans;
                }
                ans = temp;
                i++;
            }else{
                ans += s[i];
                i++;
            }

        }   
        return ans;   
    }
};