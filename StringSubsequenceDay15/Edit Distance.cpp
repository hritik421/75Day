// Given two strings s and t. Return the minimum number of operations required to convert s to t.
// The possible operations are permitted:

// Insert a character at any position of the string.
// Remove any character from the string.
// Replace any character from the string with any other character.

// Memoization

private:
  int f(int i, int j, string s, string t, vector<vector<int>>& dp){
      if(i<0) return j+1;
      if(j<0) return i+1;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(s[i]==t[j]) return f(i-1,j-1,s,t,dp);
      // insert, replace and delete
      return dp[i][j] = 1 + min(f(i,j-1,s,t,dp),
                                min(f(i-1,j-1,s,t,dp),f(i-1,j,s,t,dp)));
                                
  }
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,dp);
    }

// Tabulation

int editDistance(string s, string t) {
        // Code here
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) dp[0][j] = j;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i][j-1],
                                        min(dp[i-1][j-1],dp[i-1][j]));
            }
        }
        
        return dp[n][m];
    }

// Space Optimization

int editDistance(string s, string t) {
        // Code here
        int n = s.size(), m = t.size();
        vector<int>prev(m+1,0);
        
        //for(int i=0;i<=n;i++) dp[i][0] = i;
        for(int j=0;j<=m;j++) prev[j] = j;
        
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            curr[0]=i;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1 + min(curr[j-1],
                                        min(prev[j-1],prev[j]));
            }
            prev = curr;
        }
        
        return prev[m];
    }
