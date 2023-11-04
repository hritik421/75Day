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

int wildCard(string pattern,string str)
    {
        int n = str.size();
        int m = pattern.size();
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
        
        
        //for(int i=1;i<=n;i++) dp[i][0] = false;
        
        // Base Condition
        dp[0][0] = true;
        for(int j=1;j<=m;j++){
            bool flag = true;
            for(int k=1;k<=j;k++){
                if(pattern[k-1]!='*'){
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        
        // Iterate over all path
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                  if(str[i-1]==pattern[j-1] || pattern[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                  else if(pattern[j-1]=='*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
                  else dp[i][j] = false;
            }
        }
        
        return dp[n][m];
    }

// Space Optimization

int wildCard(string pattern,string str)
    {
        int n = str.size();
        int m = pattern.size();
        vector<bool>prev(m+1,false);
        
        
        //for(int i=1;i<=n;i++) dp[i][0] = false;
        
        // Base Condition
        prev[0] = true;
        for(int j=1;j<=m;j++){
            bool flag = true;
            for(int k=1;k<=j;k++){
                if(pattern[k-1]!='*'){
                    flag = false;
                    break;
                }
            }
            prev[j] = flag;
        }
        
        // Iterate over all path
        
        for(int i=1;i<=n;i++){
            vector<bool>curr(m+1,false);
            for(int j=1;j<=m;j++){
                  if(str[i-1]==pattern[j-1] || pattern[j-1]=='?') curr[j] = prev[j-1];
                  else if(pattern[j-1]=='*') curr[j] = prev[j] || curr[j-1];
                  else curr[j] = false;
            }
            prev = curr;
        }
        
        return prev[m];
    }

// Important if there is change in indexing, means if i represent pattern and j reperesent str.
// Then in line 110 we have to assign the value of curr[0] every time by using below logic
bool flag = true;
for(int k=1;k<=i;k++){
    if(pattern[k-1]!='*'){
        flag = false;
        break;
    }
}
curr[0] = flag;
