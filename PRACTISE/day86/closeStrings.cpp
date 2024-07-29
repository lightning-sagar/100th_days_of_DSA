class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size() != word2.size()) return false;
        unordered_map<char, int> m1, m2;
        for(char c : word1) m1[c]++;
        for(char c : word2) m2[c]++;
        // Check if both strings have the same unique characters
        unordered_set<char> s1(word1.begin(), word1.end());
        unordered_set<char> s2(word2.begin(), word2.end());
        if(s1 != s2) return false;

        // Extract the frequency values and sort them
        vector<int> freq1, freq2;
        for(auto& p : m1) freq1.push_back(p.second);
        for(auto& p : m2) freq2.push_back(p.second);
        
        sort(freq1.begin(), freq1.end());
        sort(freq2.begin(), freq2.end());
        
        return freq1 == freq2;
    }
};
