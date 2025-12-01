// Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has 
// their values changed to become the maximum value of that subarray. Return the largest sum of the given array after partitioning.

// Memoization

    int f(int i, int n, int k, vector<int>& arr, vector<int>& dp){
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        
        int len=0;
        int maxi=INT_MIN, maxAns = INT_MIN;
        
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len*maxi + f(j+1,n,k,arr,dp);
            maxAns = max(maxAns,sum);
        }
        
        return dp[i] = maxAns;
    }
    public:
    int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(n,-1);
        return f(0,n,k,arr,dp);
    }

// Tabulation

int solve(int n, int k, vector<int>& arr){
        // Code here
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int len=0;
            int maxi=INT_MIN, maxAns = INT_MIN;
            
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = len*maxi + dp[j+1];
                maxAns = max(maxAns,sum);
            }
            
            dp[i] = maxAns;
        }
        
        return dp[0];
    }
