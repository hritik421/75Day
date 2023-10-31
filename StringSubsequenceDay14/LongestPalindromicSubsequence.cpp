// Given a String, find the longest palindromic subsequence.

// NOTE: Subsequence of a given sequence is a sequence that can be derived from the given sequence by deleting some or no elements without changing the order of the remaining elements

// Memoization

 private:
  int f(int i, int j, string A, string B, vector<vector<int>>& dp){
      if(i<0 || j<0) return 0;
      
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(A[i]==B[j]) return 1 + f(i-1,j-1,A,B,dp);
      return dp[i][j] = max(f(i-1,j,A,B,dp),f(i,j-1,A,B,dp));
  }
  
  public:
    int longestPalinSubseq(string A) {
        //code here
        int n = A.size();
        string B = A;
        reverse(B.begin(),B.end());
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return f(n-1,n-1,A,B,dp);
    }
