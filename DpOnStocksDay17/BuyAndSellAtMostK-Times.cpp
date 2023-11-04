// Memoization

 private:
  int f(int ind, int trans, int A[], vector<vector<int>>& dp, int n){
      if(ind==n || trans==0) return 0;
      
      if(dp[ind][trans]!=-1) return dp[ind][trans];
      
      if(trans%2==0){
          return dp[ind][trans] = max(-A[ind] + f(ind+1,trans-1,A,dp,n),
                                        0 + f(ind+1,trans,A,dp,n));
      }
      else{
          return dp[ind][trans] = max(A[ind] + f(ind+1,trans-1,A,dp,n),
                                        0 + f(ind+1,trans,A,dp,n));
      }
  }
  public:
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(2*K+1,-1));
        return f(0,2*K,A,dp,N);
    }
