class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();   
        vector<pair<int, int>> v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {nums2[i], nums1[i]};
        }
        sort(v.rbegin(), v.rend());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0, sum = 0;
        for(int i = 0; i < n; i++) {
            sum += v[i].second;
            pq.push(v[i].second);
            if(i >= k - 1) {
                ans = max(ans, sum * v[i].first);
                sum -= pq.top();
                pq.pop();
            }

        }   
        return ans;
    }
};