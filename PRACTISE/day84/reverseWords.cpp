class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        string result = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            st.push(word);
        }
        while (st.size() != 1) {
            result += st.top() + " ";
            st.pop();
        }
        result += st.top();
        return result;
    }
};