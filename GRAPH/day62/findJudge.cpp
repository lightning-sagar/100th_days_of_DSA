    int findJudge(int n, vector<vector<int>>& trust) {
        // create ajcency list
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int a=trust[i][0];
            int b=trust[i][1];
            mp[b]++; // b is trusted by a

            mp[a]--;// a trusts b
        }
        // find judge
        for(int i=1;i<=n;i++){
            if(mp[i]==n-1) return i;// i is the judge
        }
        return -1;
    }