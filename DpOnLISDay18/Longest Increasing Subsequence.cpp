// Given an array of integers, find the length of the longest (strictly) increasing subsequence from the given array.
// Memoization

int f(int ind, int prev, int a[], vector<vector<int>>& dp, int n){
        if(ind==n) return 0;
        
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        
        int len = f(ind+1,prev,a,dp,n);
        if(prev==-1 || a[ind]>a[prev]){
            len = max(len,1 + f(ind+1,ind,a,dp,n));
        }
        
        return dp[ind][prev+1] = len;
    }
    
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       return f(0,-1,a,dp,n);
    }

// Tabulation

int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n+1,vector<int>(n+1,0));
       
       for(int ind = n-1;ind>=0;ind--){
               // Very imporatnt catch for 2nd for loop
           for(int prev=ind-1;prev>=-1;prev--){
                   // important catch of index shifting for 2nd parameter while fetching value from DP
                int len = dp[ind+1][prev+1];
                if(prev==-1 || a[ind]>a[prev]){
                    len = max(len,1 + dp[ind+1][ind+1]);
                }
                
                dp[ind][prev+1] = len;
           }
       }
       return dp[0][-1+1];
    }

// Sapce Optimized

int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<int>next(n+1,0);
       
       for(int ind = n-1;ind>=0;ind--){
           vector<int>curr(n+1,0);
           for(int prev=ind-1;prev>=-1;prev--){
                int len = next[prev+1];
                if(prev==-1 || a[ind]>a[prev]){
                    len = max(len,1 + next[ind+1]);
                }
                
                curr[prev+1] = len;
           }
           next = curr;
       }
       return next[-1+1];
    }
