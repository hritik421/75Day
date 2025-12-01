// Given two strings, find the length of longest subsequence present in both of them. Both the strings are in uppercase latin alphabets.

// Memoization

class Solution
{
    private:
        int f(int n, int m, string s1, string s2, vector<vector<int>>& dp){
            if(n<0 || m<0) return 0;
            
            if(dp[n][m]!=-1) return dp[n][m];
            
            if(s1[n]==s2[m]) return 1 + f(n-1,m-1,s1,s2,dp);
            else return dp[n][m] = max(f(n-1,m,s1,s2,dp),f(n,m-1,s1,s2,dp));
        }
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s1,s2,dp);;
    }
};

// Tabulation

int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        // Base case
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int j=0;j<=m;j++) dp[0][j]=0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // because of this if(n<0 || m<0) return 0; We have shifted dp 1 position to handle -ve index so s1[i-1] is s[i]
                // We can do this without shifting as well but writting code is bit tricky
                if(s1[i-1]==s2[j-1]) dp[i][j] =  1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }

// Space Optimization

 int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<int>prev(m+1,0);
        
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;j++){
                // We have shifted dp 1 position so s1[i-1] is s[i]
                if(s1[i-1]==s2[j-1]) curr[j] =  1 + prev[j-1];
                else curr[j] = max(prev[j],curr[j-1]);
            }
            prev = curr;
        }
        
        return prev[m];
    }
