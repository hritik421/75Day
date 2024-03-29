/*Problem Link: https://www.codingninjas.com/studio/problems/minimum-path-sum_985349
Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost
associated with it.

Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the 
numbers along the path. You need to tell the minimum sum of that path.

Note:
You can only move down or right at any point in time.

1 2 3
4 5 4
7 5 9

O/P: 19 */

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

// Tabulation

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0&&j==0) dp[0][0] = grid[0][0];
            else{
                int top=1e9+7,left=1e9+7;
                if(i>0) top = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(top,left);
            }
        }
    }
    return dp[n-1][m-1];
}

// Space Optimization

int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<int> prev(m,1e9+7);

    for(int i=0;i<n;i++){
        vector<int> curr(m,1e9+7);
        for(int j=0;j<m;j++){
            if(i==0&&j==0) curr[0] = grid[0][0];
            else{
                int top=1e9+7,left=1e9+7;
                if(i>0) top = grid[i][j] + prev[j];
                if(j>0) left = grid[i][j] + curr[j-1];
                curr[j] = min(top,left);
            }
        }
        prev = curr;
    }
    return prev[m-1];
}
//
