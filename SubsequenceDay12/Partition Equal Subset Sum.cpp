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

int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++) sum+=arr[i];
        vector<vector<int>> dp(N,vector<int>(sum/2+1,0));
        if(sum%2!=0) return 0;
        int target = sum/2;
        // Base condition
        
        for(int i=0;i<N;i++) dp[i][0] = 1;
        if(arr[0]<sum/2) dp[0][arr[0]] = 1;
        

        for(int i=1;i<N;i++){
            for(int j=0;j<=target;j++){
                // Copy-paste memoization logic
                int notTake = dp[i-1][j];
                int take = 0;
                if(j-arr[i]>=0){
                    take = dp[i-1][j-arr[i]];
                }
                dp[i][j] = take || notTake;
            }
        }
        
        return dp[N-1][sum/2];
    }

// Space Optimization

int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i=0;i<N;i++) sum+=arr[i];
        vector<int>prev(sum/2+1,0);
        if(sum%2!=0) return 0;
        int target = sum/2;
        // Base condition
        
        prev[0] = 1;
        if(arr[0]<sum/2) prev[arr[0]] = 1;
        

        for(int i=1;i<N;i++){
            vector<int> curr(target+1,0);
            for(int j=0;j<=target;j++){
                // Copy-paste memoization logic
                int notTake = prev[j];
                int take = 0;
                if(j-arr[i]>=0){
                    take = prev[j-arr[i]];
                }
                curr[j] = take || notTake;
            }
            prev = curr;
        }
        
        return prev[sum/2];
    }
