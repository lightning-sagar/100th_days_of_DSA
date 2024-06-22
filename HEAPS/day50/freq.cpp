vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int, int> mp;
    // 1st pass to store the frequency of each element
    for(int i=0;i<nums.size();i++){
        mp[nums[i]]++;
    }
    // 2nd pass to store the elements in decreasing order of frequency
    priority_queue<pair<int, int>> pq;
    for(auto it: mp){
        pq.push({it.second, it.first});
    }
    // 3rd pass to get the top k elements sagar 
    vector<int> ans;
    for(int i=0;i<k;i++){
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}