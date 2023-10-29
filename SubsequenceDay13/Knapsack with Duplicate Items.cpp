// Given a set of N items, each with a weight and a value, represented by the array w and val respectively. Also, a knapsack with weight limit W.
// The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
// Note: Each item can be taken any number of times.

// Memoization

class Solution{
private: 
    int f(int ind, int w, int val[], int wt[], vector<vector<int>>& dp){
        if(ind==0){
            return ((int)(w/wt[0]))*val[0];
        }
        
        if(dp[ind][w]!=-1) return dp[ind][w];
        
        int notPick = 0 + f(ind-1,w,val,wt,dp);
        int pick = 0;
        if(w>=wt[ind]) pick = val[ind] + f(ind, w-wt[ind],val,wt,dp);
        
        return dp[ind][w] = max(pick,notPick);
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return f(N-1,W,val,wt,dp);
    }
};

// Tabulation

int knapSack(int N, int W, int val[], int wt[])
{
    // code here
    vector<vector<int>> dp(N,vector<int>(W+1,0));
    
    // Base Case and make sure to add equals to sign
    for(int w=0;w<=W;w++){
        dp[0][w] = ((int)(w/wt[0]))*val[0];
    }
    
    // Explore all possibilities
    
    for(int ind=1;ind<N;ind++){
        for(int w=0;w<=W;w++){
            int notPick = 0 + dp[ind-1][w];
            int pick = 0;
            if(w>=wt[ind]) pick = val[ind] + dp[ind][w-wt[ind]];
            dp[ind][w]=max(pick,notPick);
        }
    }
    return dp[N-1][W];
}
