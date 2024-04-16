class Solution {
public:
    int longestValidParentheses(string s) {
        int maxLen = 0;
        stack<int> st;
        st.push(-1); // Push -1 onto the stack to handle edge cases

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else { // s[i] == ')'
                st.pop();
                if (!st.empty()) {//agar empty nahi hua then get maxlen
                    maxLen = max(maxLen, i - st.top());
                } else {
                    st.push(i); // Update the starting index of a potential new valid substring
                }
            }
        }

        return maxLen;
    }
};
