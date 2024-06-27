class Solution {
public:
    bool isSafe(int& row,int& col,vector<vector<char>>& v, char& c)
    {
        for(int i=0;i<9;i++)
        {
            if(v[row][i]==c) return false;
            if(v[i][col]==c) return false;
            if(v[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
        }
        return true;
    }
    void solve(int i,int j,vector<vector<char>>& v,int& flag)
    {
        if(i==9){
            flag=0;
            return;
            
        }
        if(v[i][j]!='.')
        {
            if(j<8) solve(i,j+1,v,flag);
            else solve(i+1,0,v,flag);
        }
        else{
        for(char c='9';c>='1';c--)
        {
            if(isSafe(i,j,v,c))
            { 
                v[i][j]=c;
                if(j==8) solve(i+1,0,v,flag);
                else solve(i,j+1,v,flag);
                if(flag==0) return;
                v[i][j]='.';
            }
        } 
        }
    }
    void solveSudoku(vector<vector<char>>& v) {
        int flag=-1;
        solve(0,0,v,flag);
    }
};