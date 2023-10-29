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
