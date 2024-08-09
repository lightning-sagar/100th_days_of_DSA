class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        int l = 0, r = n - 1;
        while (l < r) {
            
            int mid = l + (r - l) / 2;
            int count = 0;
            int i = 0, j = n - 1;
            while (i <= j) {
                if (costs[i] <= costs[j]) {
                    count += i <= mid ? i : mid;
                    i++;
                } else {
                    count += j >= mid ? j : mid;
                    j--;
                }
            }   

            if (count > candidates) {
                r = mid - 1;
            } else {
                l = mid;
            }
        }       

        return costs[l];

    }
};