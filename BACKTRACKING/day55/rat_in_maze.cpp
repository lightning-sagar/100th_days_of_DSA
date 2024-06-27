#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>> &m, vector<vector<int>> &vis,int i,int j,int n,vector<string> &ans,string s){
    if(i == n-1 && j == n-1){
        ans.push_back(s);
        return;
    }
    if(isSafe(m+1,i,j,n)){
        vis[m][n]=1;
        solve(m,vis,i+1,j,n,ans,s+"D");
        vis[m][n]=0;
    }
    if(isSafe(m-1,i,j,n)){
        vis[m][n]=1;
        solve(m,vis,i-1,j,n,ans,s+"U");
        vis[m][n]=0;
    }
    if(isSafe(m,i+1,j,n)){
        vis[m][n]=1;
        solve(m,vis,i,j+1,n,ans,s+"R");
        vis[m][n]=0;
    }
    if(isSafe(m,i-1,j,n)){
        vis[m][n]=1;
        solve(m,vis,i,j-1,n,ans,s+"L");
        vis[m][n]=0;
    }
}

bool isSafe(int m,int i,int j,int n){
    if(m>=0 && m<n && i>=0 && i<n && j>=0 && j<n)
        return true;
    return false;
}
vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        if(m[0][0] == 0)
            return ans;
        vector<vector<int>> vis(n,vector<int>(n,0));
        solve(m,0,0,n,ans,"",vis);
        return ans;
}