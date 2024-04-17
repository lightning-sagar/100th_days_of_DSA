int checkRedundancy(string s) {
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if(ch == ')') {
            // Pop until we encounter an opening parenthesis or an operator
            bool hasOperator = false;
            while(!st.empty() && st.top() != '(') {
                if(st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/') {
                    hasOperator = true;
                }
                st.pop();
            }
            // If no operator found, redundant parentheses exist
            if(!hasOperator) {
                return true;
            }
            // Pop the opening parenthesis
            st.pop();
        } else {
            // Push opening parenthesis and operators onto the stack
            st.push(ch);
        }
    }
    return false;
}
