int totalFruits(int N, vector<int> &fruits){
    unordered_map<int,int> m;
    int left = 0; int right = 0;
    int ans  = 0;
    while(right<N){
        //push in map
        m[fruits[right]]++;
        if(m.size()>2){
            if(m[fruits[left]]==1){
                //delete them
                m.erase(fruits[left]);
            }
            else{
                //decrement
                m[fruits[left]]--;
            }
            left++;
        }
        ans = max(ans,right-left+1);
        right++;
    }
    return ans;
}
 