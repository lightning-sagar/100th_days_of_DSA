//merfe kth sorted array using heap
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mergeKSortedArrays(vector<vector<int>>& arrays) {
        int k = arrays.size();
        priority_queue<pair<int,int>> pq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            if(arrays[i].size() != 0){
                pq.push({arrays[i][0],i});
            }
        }
        while(!pq.empty()){
            pair<int,int> temp = pq.top();
            pq.pop();
            ans.push_back(temp.first);
            int index = temp.second;
            if(arrays[index].size() > 1){
                arrays[index].erase(arrays[index].begin());
                pq.push({arrays[index][0],index});
            }
        }
        return ans;
    }
};
