// Given an array arr of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Try to solve it using memoization

private:
    int f(int arr[],int n, int tar, vector<vector<int>>& dp){
        if(tar<0) return 0;
        if(n==0){
            if(tar==0 && arr[n]==0) return 2; // for both pick and notPick
            if(tar==0 || tar == arr[n]) return 1;
            return 0;
        }
        
        if(dp[n][tar]!=-1) return dp[n][tar];
        int pick = f(arr,n-1,tar-arr[n],dp);
        int notPick = f(arr,n-1,tar,dp);
        return dp[n][tar] = (pick + notPick)%1000000007;
    }

public:
int perfectSum(int arr[], int n, int target)
{
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    return f(arr,n-1,target,dp);
}
	  

// Space optimized approach

int perfectSum(int arr[], int n, int target)
{
    vector<int>prev(target+1,0);
    prev[0] = 1;

	for(int i=0;i<n;i++){
	    vector<int> curr(target+1,0);
	    for(int j=0;j<=target;j++){
		// Copy-paste memoization logic
		int notTake = prev[j];
		int take = 0;
		if(j-arr[i]>=0){
		    take = prev[j-arr[i]];
		}
		curr[j] = (take + notTake)%1000000007;
	    }
	    prev = curr;
	}
        
        return prev[target];
}
