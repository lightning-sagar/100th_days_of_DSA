class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.size();
        int l2 = word2.size();
        int n = max(l1,l2);
        string ans = "";
        for(int i=0;i<n;i++){
           for(i<l1){
               ans += word1[i];
           }
           for(i<l2){
               ans += word2[i];
           }
        }
        return ans;
    }
};