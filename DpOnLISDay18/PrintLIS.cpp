// This is the only way, so please remember it

vector<int> longestIncreasingSubsequence(int n, vector<int>& a) {
        // Code here
       vector<int>dp(n,1),hash(n,0);
       
       int ans = 1,lastIndex=0;
       for(int ind=1;ind<n;ind++){
           hash[ind]=ind;
           for(int prev=0;prev<ind;prev++){
               if(a[prev]<a[ind] && dp[ind]<(1+dp[prev])){
                   dp[ind] = 1+dp[prev];
                   hash[ind] = prev;
               }
           }
           if(dp[ind]>ans){
               ans = dp[ind];
               lastIndex = ind;
           }
       }
       
       vector<int> lis;
       lis.push_back(a[lastIndex]);
       while(hash[lastIndex]!=lastIndex){
           lastIndex = hash[lastIndex];
           lis.push_back(a[lastIndex]);
       }
       
       reverse(lis.begin(),lis.end());
       return lis;
       
    }
