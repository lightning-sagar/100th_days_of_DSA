class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int flag = 1;
                for(int k=0;k<n;k++){
                    if(grid[i][k] != grid[k][j]){
                        flag = 0;
                        break;
                    }
                }
                if(flag) count++;
            }
        }    
        return count;
    }
};