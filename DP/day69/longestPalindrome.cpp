class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, end = 0, max_len = 0;
        int n = s.size()-1;
        for(int i = 0;i<=n;i++){
            int len1 = expandAroundCenter(s,i,i);
            int len2 = expandAroundCenter(s,i,i+1);
            max_len = max(len1,len2);
            if(max_len > end-start){
                start = i - ((max_len-1)/2);
                end = i + (max_len/2);
            }
        }
        return s.substr(start,max_len);
    }
    
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return right - left - 1;
    }
};
