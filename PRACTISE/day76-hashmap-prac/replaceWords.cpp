class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> st(dictionary.begin(), dictionary.end());
        
        string ans;
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            string prefix;
            for (int i = 1; i <= word.size(); ++i) {
                prefix = word.substr(0, i);
                if (st.find(prefix) != st.end()) {
                    break;
                }
            }
            ans += prefix + " ";
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        
        return ans;
    }
};