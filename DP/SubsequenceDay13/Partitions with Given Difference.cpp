// Given an array arr, partition it into two subsets(possibly empty) such that their union is the original array. Let the sum of the element of these two subsets be S1 and S2. 

// Given a difference d, count the number of partitions in which S1 is greater than or equal to S2 and the difference S1 and S2 is equal to d.
// since the answer may be large return it modulo 109 + 7.

// Memoization

class Solution {
  private:
    int mod = 1e9+7;
    int f(int n, int d, int tar, vector<int>& arr, vector<vector<int>>& dp){
        if(n==0){
            if(tar==0 && arr[0]==0) return 2;
            if(tar==0 || tar==arr[0]) return 1;
            return 0;
            //return tar == 0;
        }
        
        if(dp[n][tar]!=-1) return dp[n][tar];
        
        int notPick = f(n-1,d,tar,arr,dp);
        int pick = 0;
        if(tar-arr[n]>=0){
            pick = f(n-1,d,tar-arr[n],arr,dp);
        }
        
        return dp[n][tar] = (pick + notPick)%mod;
    }
    
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Mathematical stuff
        // S1-S2=d
        // S1+S2=sum
        // 2S1=d+sum
        // s1=(sum+d)/2;
        // Now find count subset of s1
        int sum = 0;
        for(int i=0;i<n;i++) sum+=arr[i];
      
        // If (sum + d) is odd, then (sum + d) / 2 is not an integer, so:
        // S1 cannot be an integer sum
        // No subset can have fractional sum
        // Therefore, no valid partition exists
        // So we must return 0.
      
        if((sum+d)%2) return 0;
        int tar = ((sum+d)/2)%mod;
        
        vector<vector<int>> dp(n,vector<int>(tar+1,-1));
        return f(n-1,d,tar,arr,dp);
    }
};

// Tabulation

int countPartitions(int n, int d, vector<int>& arr) {
        // Mathematical stuff
        // S1-S2=d
        // S1+S2=sum
        // 2S1=d+sum
        // s1=(sum+d)/2;
        // Now find count subset of s1
        int sum = 0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if((sum+d)%2) return 0;
        int tar = ((sum+d)/2)%mod;
        
        vector<vector<int>> dp(n,vector<int>(tar+1,0));
        
        // Base condition
        if(arr[0]==0) dp[0][0]=2;
        else {
            dp[0][0]=1;
            if(arr[0]<=tar) dp[0][arr[0]]=1;
        }
        
        // write for loop
        for(int i=1;i<n;i++){
            for(int t=0;t<=tar;t++){
                // Copy Paste recursion logic here
                int notPick = dp[i-1][t];
                int pick = 0;
                if(t-arr[i]>=0){
                    pick = dp[i-1][t-arr[i]];
                }
                dp[i][t]=(pick+notPick)%mod;
            }
        }
        
        return dp[n-1][tar];
    }

// Space Optimization

int countPartitions(int n, int d, vector<int>& arr) {
        // Mathematical stuff
        // S1-S2=d
        // S1+S2=sum
        // 2S1=d+sum
        // s1=(sum+d)/2;
        // Now find count subset of s1
        int sum = 0;
        for(int i=0;i<n;i++) sum+=arr[i];
        if((sum+d)%2) return 0;
        int tar = ((sum+d)/2)%mod;
        
        vector<int> prev(tar+1,0);
        
        // Base condition
        if(arr[0]==0) prev[0]=2;
        else {
            prev[0]=1;
            if(arr[0]<=tar) prev[arr[0]]=1;
        }
        
        // write for loop
        for(int i=1;i<n;i++){
            vector<int> curr(tar+1,0);
            for(int t=0;t<=tar;t++){
                // Copy Paste recursion logic here
                int notPick = prev[t];
                int pick = 0;
                if(t-arr[i]>=0){
                    pick = prev[t-arr[i]];
                }
                curr[t]=(pick+notPick)%mod;
            }
            prev=curr;
        }
        
        return prev[tar];
    }
