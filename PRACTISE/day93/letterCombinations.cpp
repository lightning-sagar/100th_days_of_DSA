class Solution {
public:
    void solve(string digits, vector<string> v, int i, string s, vector<string>& ans){
        if(i == digits.size()){
            if(s.size() != 0) ans.push_back(s);
            return;
        }
        string str = v[digits[i] - '0'];
        for(int j = 0; j < str.size(); j++){
            s += str[j];
            solve(digits,v,i+1,s,ans);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        vector<string> v = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string s = "";
        solve(digits,v,0,s,ans);
        return ans;      
    }
};