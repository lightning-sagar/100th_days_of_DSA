class Solution{
public:
    string decodeString(string s){
        stack<int>num;
        stack<char>st;
        string ans;
        bool check=false;
        for(char c: s){
            string temp;
            if(isdigit(c)){
                if(check==false){
                    num.push(c-'0');
                }
                else{
                    int n=num.top();
                    num.pop();
                    n=(n*10)+(c-'0');
                    num.push(n);
                }
                check=true;
            }
            else if(c==']'){
                while(st.top()!='['){
                    temp.push_back(st.top());
                    st.pop();
                }
                st.pop();
                reverse(temp.begin(), temp.end());
                int n=num.top();
                while(n>0){
                    for(int i=0; i<temp.size(); i++){
                        st.push(temp[i]);
                    }
                    n--;
                }
                num.pop();
                check=false;
            }
            else{
                st.push(c);
                check=false;
            }
        }
        while(!st.empty()){
            if(st.top()!='['){
                ans.push_back(st.top());
            }
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};