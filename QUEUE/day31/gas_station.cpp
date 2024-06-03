class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int loss=0;
        int bal = 0;
        int s = 0;
        for (int i=0;i<gas.size();i++){
            bal += gas[i]-cost[i];
            if(bal<0){
                s = i+1;
                loss+=bal;
                bal=0;
            }
        }
        if(loss+bal>=0) return s;
        else return -1;
    }
};