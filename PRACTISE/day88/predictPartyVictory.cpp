class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> qR, qD;  
        for(int i = 0; i < n; i++){
            if(senate[i] == 'R') qR.push(i);
            else qD.push(i);
        }
        while(!qR.empty() && !qD.empty()){
            int rIndex = qR.front();   
            qR.pop();
            int dIndex = qD.front();
            qD.pop();
            if(rIndex < dIndex){
                qR.push(rIndex + n);   
            }
            else{
                qD.push(dIndex + n);   
            }
        }
        return qR.empty() ? "Dire" : "Radiant";  
    }
};
