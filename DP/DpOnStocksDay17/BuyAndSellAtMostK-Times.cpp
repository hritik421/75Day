

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

// Tabulation

int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(2*K+1,0));
        
        for(int ind=N-1;ind>=0;ind--){
            for(int trans=1;trans<=2*K;trans++){
                if(trans%2==0){
                    dp[ind][trans] = max(-A[ind] + dp[ind+1][trans-1],
                                                    0 + dp[ind+1][trans]);
                }
                else{
                    dp[ind][trans] = max(A[ind] + dp[ind+1][trans-1],
                                                    0 + dp[ind+1][trans]);
                }
            }
        }
        return dp[0][2*K];
    }

// Space Optimization

int maxProfit(int K, int N, int A[]) {
        // code here
        vector<int>ahead(2*K+1,0);
        
        for(int ind=N-1;ind>=0;ind--){
            vector<int>curr(2*K+1,0);
            for(int trans=1;trans<=2*K;trans++){
                if(trans%2==0){
                    curr[trans] = max(-A[ind] + ahead[trans-1],
                                                    0 + ahead[trans]);
                }
                else{
                    curr[trans] = max(A[ind] + ahead[trans-1],
                                                    0 + ahead[trans]);
                }
            }
            ahead = curr;
        }
        return ahead[2*K];
    }
