// MOST ASKED IN INTERVIEW

// You are given weights and values of N items, put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// Note that we have only one quantity of each item.

// Memoization

class Solution
{
    private:
    int f(int w, int n, int wt[], int val[], vector<vector<int>> &dp){
        if(n==0){
            if(wt[0]<=w) return val[0];
            return 0;
        }
        
        if(dp[n][w]!=-1) return dp[n][w];
        
        int notPick = 0 + f(w,n-1,wt,val,dp);
        int pick = INT_MIN;
        if(wt[n]<=w) pick = val[n] + f(w-wt[n],n-1,wt,val,dp);
        
        return dp[n][w] = max(pick,notPick);
    }
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,-1));
       return f(W,n-1,wt,val,dp);
    }
};

