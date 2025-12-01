// Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

// answer[i] % answer[j] == 0, or
// answer[j] % answer[i] == 0
// If there are multiple sequences with the largest size, return any of them.

** Very Important point**
// It is subset not subsequence so order doesn't matter.

  vector<int> LargestSubset(int n, vector<int>& arr) {
        // Code here
         vector<int>dp(n,1),hash(n,0);
         sort(arr.begin(),arr.end());
         
         int lastIndex = 0;int maxi=1;
         for(int i=1;i<n;i++){
             hash[i]=i;
             for(int j=0;j<i;j++){
                 if((arr[i]%arr[j]==0 || arr[j]%arr[i]==0) && dp[i]<1+dp[j]){
                     dp[i] = 1+dp[j];
                     hash[i]=j;
                 }
             }
             if(maxi<dp[i]){
                 maxi=dp[i];
                 lastIndex = i;
             }
         }
         
         vector<int> res;
         res.push_back(arr[lastIndex]);
         
         while(hash[lastIndex]!=lastIndex){
             lastIndex = hash[lastIndex];
             res.push_back(arr[lastIndex]);
         }
         
         reverse(res.begin(),res.end());
         
         return res;
    }
