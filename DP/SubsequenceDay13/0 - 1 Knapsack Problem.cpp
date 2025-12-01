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

// Tabulation

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> dp(n,vector<int>(W+1,0));
       
       // Base case
       for(int i=wt[0];i<=W;i++){
           dp[0][i] = val[0];
       }
       
       // Explore all possibilities
       for(int i=1;i<n;i++){
           for(int j=0;j<=W;j++){
                int notPick = 0 + dp[i-1][j];
                int pick = INT_MIN;
                if(wt[i]<=j) pick = val[i] + dp[i-1][j-wt[i]];
                dp[i][j] = max(pick,notPick);
           }
       }
       
       
       return dp[n-1][W];
    }

// Space Optimization

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(W+1,0);
       
       // Base case
       for(int i=wt[0];i<=W;i++){
           prev[i] = val[0];
       }
       
       // Explore all possibilities
       for(int i=1;i<n;i++){
           vector<int> curr(W+1,0);
           for(int j=0;j<=W;j++){
                int notPick = 0 + prev[j];
                int pick = INT_MIN;
                if(wt[i]<=j) pick = val[i] + prev[j-wt[i]];
                curr[j] = max(pick,notPick);
           }
           prev=curr;
       }
       
       
       return prev[W];
    }

// Using only one array

int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<int> prev(W+1,0);
       
       // Base case
       for(int i=wt[0];i<=W;i++){
           prev[i] = val[0];
       }
       
       // Explore all possibilities
       for(int i=1;i<n;i++){
           for(int j=W;j>=0;j--){
                int notPick = 0 + prev[j];
                int pick = INT_MIN;
                if(wt[i]<=j) pick = val[i] + prev[j-wt[i]];
                prev[j] = max(pick,notPick);
           }
       }
       
       
       return prev[W];
    }
