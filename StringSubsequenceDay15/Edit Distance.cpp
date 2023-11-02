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
