class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        queue<int> q;
        //we needd to store the index of the character
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }     
        for(int i=0;i<n;i++){
            if(mp[s[i]]==1){
                q.push(i);
            }
        }
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
};