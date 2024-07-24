class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lastocc(26,0);
        for(int i = 0;i < n;i++) lastocc[s[i]-'a'] = i;
        
        int maxidx = -1;
        int endidxprevpart = -1; 
        vector<int> vec;
        for(int i = 0;i < n;i++) {
            maxidx = max(lastocc[s[i]-'a'],maxidx);
            if(i == maxidx) {
                vec.push_back(i-endidxprevpart);
                endidxprevpart = i;
            }    
        }
        return vec;
    }
};