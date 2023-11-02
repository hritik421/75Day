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
