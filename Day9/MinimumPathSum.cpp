// Memoization

#include <bits/stdc++.h> 
int f(int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if(n==0 && m==0) return grid[0][0];
    if(n<0 || m<0) return 1e9+7;

    if(dp[n][m]!=-1) return dp[n][m];

    int top = grid[n][m] + f(n-1,m,grid,dp);
    int left = grid[n][m] + f(n,m-1,grid,dp);

    return dp[n][m] = min(top,left);
}

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return f(n-1,m-1,grid,dp);
}

