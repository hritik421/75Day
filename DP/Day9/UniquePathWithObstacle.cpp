// You are given a matrix grid of n x  m size consisting of values 0 and 1. A value of 1 means that you can enter that cell and 0 implies that entry to that cell is not allowed.

// You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner (n, m) such that you can only move in the right or down direction from every cell.

// Your task is to calculate the total number of ways of reaching the target modulo (109+7).
// Note: The first (1, 1) and last cell (n, m) of the grid can also be 0


// Memoization

//User function Template for C++

class Solution {
  private:
  int mod = 1e9 + 7;
  int f(int n, int m, vector<vector<int>>& grid, vector<vector<int>> & dp){
      if(n>=0 && m>=0 && grid[n][m]==0) return 0;
      if(n==0 && m==0) return 1;
      
      if(n<0 || m<0) return 0;
      
      if(dp[n][m]!=-1) return dp[n][m];
      
      int up = f(n-1,m,grid,dp);
      int left = f(n,m-1,grid,dp);
      
      return dp[n][m] = (up + left)%mod;
      
  }
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1,m-1,grid,dp);
    }
};

// Tabulation

public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<vector<int>> dp(n, vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                // base condition
                if(grid[i][j]==0) dp[i][j]=0;
                else if(i==0 && j==0) dp[i][j]=1;
                else{
                    int up=0,left=0;
                    if(i>0) up = dp[i-1][j];
                    if(j>0) left = dp[i][j-1];
                    dp[i][j] = (up + left)%mod;
                }
            }
        }
        
        return dp[n-1][m-1];
    }

// Space Optimization

public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        // code here
        vector<int> prev(m,0);
        
        for(int i=0;i<n;i++){
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                // base condition
                if(grid[i][j]==0) curr[j]=0;
                else if(i==0 && j==0) curr[j]=1;
                else{
                    int up=0,left=0;
                    if(i>0) up = prev[j];
                    if(j>0) left = curr[j-1];
                    curr[j] = (up + left)%mod;
                }
            }
            prev=curr;
        }
        
        return prev[m-1];
    }
