class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1, min_val = 0;
        for (int i = 0; i < cost.size(); i++) {
            gas[i] -= cost[i];
            if (i > 0) gas[i] += gas[i - 1];
            if (gas[i] < min_val) {
                min_val = gas[i];
                res = i;
            }
        }
        if (gas.back() < 0) return -1;
        return res + 1;
        // invariant, maintain a net positive when travelling clockwise
    }
};