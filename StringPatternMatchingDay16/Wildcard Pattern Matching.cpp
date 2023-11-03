// Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .

// The wildcard pattern can include the characters ‘?’ and ‘*’
// ‘?’ – matches any single character
// ‘*’ – Matches any sequence of characters (including the empty sequence)

// Note: The matching should cover the entire str (not partial str).

// Memoization

class Solution{
  private:
  bool f(int i, int j, string s, string p, vector<vector<int>>& dp){
      if(j<0 && i<0) return true;
      
      if(j<0 && i>=0) return false;
      
      if(i<0 && j>=0) {
          while(j>=0) {
              if(p[j]!='*') return false;
              j--;
          }
          return true;
      }
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(s[i]==p[j] || p[j]=='?') return dp[i][j] = f(i-1,j-1,s,p,dp);
      
      if(p[j]=='*') return dp[i][j] = f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
      
      return dp[i][j] = false;
  }
  public:
/*You are required to complete this method*/
    int wildCard(string pattern,string str)
    {
        int n = str.size();
        int m = pattern.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        
        return f(n-1,m-1,str,pattern,dp);
    }
};

// Tabulation



 
