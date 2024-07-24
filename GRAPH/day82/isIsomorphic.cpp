class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mp[256] = {0};
        bool st[256] = {false};


        for(int i = 0; i < s.size(); i++){
            char a = s[i];

            st[t[i]] = true;

            if(mp[a] != 0){
                if(mp[a] != a + a - t[i]) return false;
            }

            mp[a] = a + a - t[i];
        }

        int stcount = 0, mpcount = 0;
        for(int i = 0; i < 256; i++)
        {
            if(st[i]) stcount++;

            if(mp[i]) mpcount++;
        }

        return stcount == mpcount;
    }
};