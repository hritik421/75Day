// Given a string, find the minimum number of characters to be inserted to convert it to palindrome.

// Eg: Codingninjas
// Palindromic part is --> ingni
// To make whole string palindrome, now we have to add duplicate char other than "ingni". So we can say that answer will be (n - LongestCommonPalindrome Length).


// Memoization

private:
    int LongestCommonPalindrome(int i, int j, string A, string B, vector<vector<int>>& dp){
          if(i<0 || j<0) return 0;
          
          if(dp[i][j]!=-1) return dp[i][j];
          
          if(A[i]==B[j]) return 1 + LongestCommonPalindrome(i-1,j-1,A,B,dp);
          return dp[i][j] = max(LongestCommonPalindrome(i-1,j,A,B,dp),LongestCommonPalindrome(i,j-1,A,B,dp));
      }
public:
    int findMinInsertions(string S){
        // code here 
        string S2 = S;
        reverse(S2.begin(),S2.end());
        int n = S.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return n - LongestCommonPalindrome(n-1,n-1,S,S2,dp);
        
    }
