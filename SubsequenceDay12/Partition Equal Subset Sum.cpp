// Given an array arr[] of size N, check if it can be partitioned into two parts such that the sum of elements in both parts is the same.

// Memoization
// User function Template for C++

class Solution{
private:
    int f(int N, int target, int arr[], vector<vector<int>>& dp){
        if(N==0) return arr[0] == target;
        if(target == 0) return 1;
        
        if(dp[N][target]!=-1) return dp[N][target];
        
        int notTake = f(N-1,target,arr,dp);
        int take = 0;
        if(target-arr[N]>=0){
            take = f(N-1,target-arr[N],arr,dp);
        }
        
        return dp[N][target] = take || notTake;
    }
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        
        for(int i=0;i<N;i++) sum+=arr[i];
        vector<vector<int>> dp(N,vector<int>(sum/2+1,-1));
        if(sum%2!=0) return 0;
        
        return f(N-1,sum/2,arr,dp);
    }
};

// Tabulation

