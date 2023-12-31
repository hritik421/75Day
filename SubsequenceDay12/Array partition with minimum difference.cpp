// Space optimized

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
	  int sum = 0;
        int N = arr.size();
        for(int i=0;i<N;i++) sum+=arr[i];
        
        int target = sum/2+1;
        vector<int>prev(target+1,0);

        // Base condition
        prev[0] = 1;
        if(arr[0]<=target) prev[arr[0]] = 1;

        for(int i=1;i<N;i++){
            vector<int> curr(target+1,0);
            for(int j=1;j<=target;j++){
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
        
        int ans = INT_MAX;
        for(int i=0;i<=target;i++){
            if(prev[i]==1){
                ans = min(ans,abs(i-(sum-i)));
            }
        }
        return ans;
}
