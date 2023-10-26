// Given an array arr of non-negative integers and an integer sum, the task is to count all subsets of the given array with a sum equal to a given sum.

// Note: Answer can be very large, so, output answer modulo 109+7

// Try to solve it using memoization

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
