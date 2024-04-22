class Solution {
public:
    string removeDuplicateLetters(string s) {
        short last[26];
        bool seen[26] = {false};

        char stack[26];
        int top = -1;
        int len = s.length();

        for (int i = 0; i < len; ++i)
            last[s[i] - 'a'] = i;

        for (int i = 0; i < len; ++i){
            if (!seen[s[i] - 'a']){

                while(top != -1 && s[i] < stack[top] && last[stack[top] - 'a'] > i)
                    seen[stack[top--] - 'a'] = false;

                seen[s[i] - 'a'] = true;
                stack[++top] = s[i];
            }
        }

        return string(stack, top + 1);        
    }
};