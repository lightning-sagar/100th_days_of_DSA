string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[a1[i]]++;
    }
    for(int i=0;i<m;i++){
        if(mp[a2[i]]==0 || mp[a2[i]]<0) 
            return "No";
    }
    return "Yes";
}


1 2 3 4 5 6 7 8
1 2 3 1