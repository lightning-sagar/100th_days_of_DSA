class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n = spells.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int l = 0;
            int r = potions.size() - 1;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if((long long)spells[i] * potions[mid] >= success){
                    r = mid - 1;
                }else{
                    l = mid + 1;
                }
            }
            ans[i] = potions.size() - l;
        }   
        return ans;
    }
};