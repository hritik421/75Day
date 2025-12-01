// Given two strings S and T of length n and m respectively. Find count of distinct occurrences of T in S as a sub-sequence. 

// Input:
// S = "banana" , T = "ban"
// Output: 3
// Explanation: There are 3 sub-sequences:
// [ban], [ba n], [b an].

// Memoization

 private:
    int f(int i, int j, string S, string T, vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(S[i]==T[j]){
            return f(i-1,j-1,S,T,dp) + f(i-1,j,S,T,dp);
        }
        
        return dp[i][j] = f(i-1,j,S,T,dp);
    }
    
    public:
    int subsequenceCount(string S, string T)
    {
      //Your code here
      int n = S.size(), m = T.size();
      vector<vector<int>> dp(n,vector<int>(m,-1));
      
      return f(n-1,m-1,S,T,dp);
    }

// Tabulation

int subsequenceCount(string S, string T)
    {
      //Your code here
      int n = S.size(), m = T.size();
      vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      
      for(int i=0;i<=n;i++) dp[i][0] = 1;
      
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(S[i-1]==T[j-1]){
                  dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%mod;
              }
              else{
                  dp[i][j] = (dp[i-1][j])%mod;
              }
          }
      }
      
      return dp[n][m];
    }

// Space Optimization

int subsequenceCount(string S, string T)
    {
      //Your code here
      int n = S.size(), m = T.size();
      vector<int>prev(m+1,0),curr(m+1,0);
      
      prev[0] = curr[0] = 1;
      
      for(int i=1;i<=n;i++){
          for(int j=1;j<=m;j++){
              if(S[i-1]==T[j-1]){
                  curr[j] = (prev[j-1] + prev[j])%mod;
              }
              else{
                  curr[j] = (prev[j])%mod;
              }
          }
          prev = curr;
      }
      
      return prev[m];
    }

// Only using 1 array

int subsequenceCount(string S, string T)
    {
      //Your code here
      int n = S.size(), m = T.size();
      vector<int>prev(m+1,0);
      
      prev[0] = 1;
      
      for(int i=1;i<=n;i++){
       // Imp iterating from right to left
          for(int j=m;j>=1;j--){
              if(S[i-1]==T[j-1]){
                  prev[j] = (prev[j-1] + prev[j])%mod;
              }
          }
      }
      
      return prev[m];
    }
