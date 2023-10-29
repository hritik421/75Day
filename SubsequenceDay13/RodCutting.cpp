// Given a rod of length N inches and an array of prices, price[]. price[i] denotes the value of a piece of length i. 
// Determine the maximum value obtainable by cutting up the rod and selling the pieces.


// Memoization

private:
    int f(int ind, int n, int price[], vector<vector<int>>& dp){
        if(ind==0) return n*price[0];
        
        if(dp[ind][n]!=-1) return dp[ind][n];
        
        int rodLength = ind+1;
        int notPick = f(ind-1,n,price,dp);
        int pick = INT_MIN;
        if(rodLength<=n) pick = price[ind] + f(ind,n-rodLength,price,dp);
        return dp[ind][n] = max(pick,notPick);
    }
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,n,price,dp);
    }

// Tabulation

 int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n,vector<int>(n+1,0));
        
        // Base case
        for(int i=0;i<=n;i++) dp[0][i] = i*price[0];
        
        // Explore all possibilities
        for(int ind=1;ind<n;ind++){
            for(int N=0;N<=n;N++){
                int rodLength = ind+1;
                int notPick = dp[ind-1][N];
                int pick = INT_MIN;
                if(rodLength<=N) pick = price[ind] + dp[ind][N-rodLength];
                dp[ind][N] = max(pick,notPick);
            }
        }
        
        return dp[n-1][n];
    }

// Space Optimization
int cutRod(int price[], int n) {
        //code here
        vector<int>prev(n+1,0);
        
        // Base case
        for(int i=0;i<=n;i++) prev[i] = i*price[0];
        
        // Explore all possibilities
        for(int ind=1;ind<n;ind++){
            vector<int>curr(n+1,0);
            for(int N=0;N<=n;N++){
                int rodLength = ind+1;
                int notPick = prev[N];
                int pick = INT_MIN;
                if(rodLength<=N) pick = price[ind] + curr[N-rodLength];
                curr[N] = max(pick,notPick);
            }
            prev = curr;
        }
        
        return prev[n];
    }

// Using only 1 vector/array

int cutRod(int price[], int n) {
        //code here
        vector<int>prev(n+1,0);
        
        // Base case
        for(int i=0;i<=n;i++) prev[i] = i*price[0];
        
        // Explore all possibilities
        for(int ind=1;ind<n;ind++){
            for(int N=0;N<=n;N++){
                int rodLength = ind+1;
                int notPick = prev[N];
                int pick = INT_MIN;
                if(rodLength<=N) pick = price[ind] + prev[N-rodLength];
                prev[N] = max(pick,notPick);
            }
        }
        
        return prev[n];
    }
