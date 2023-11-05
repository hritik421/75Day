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
