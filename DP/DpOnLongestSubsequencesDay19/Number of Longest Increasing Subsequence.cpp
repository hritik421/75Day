// Tricky question

int NumberofLIS(int n, vector<int>&arr) {
        // Code here
        vector<int> dp(n,1),count(n,1 );
        int maxi = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]>arr[j] && dp[i]<1+dp[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                    count[i] = count[j];
                    maxi = max(dp[i],maxi);
                }
                else if(arr[i]>arr[j] && dp[i]==1+dp[j]){
                    count[i]+=count[j];
                }
            }
        }
        
        int res = 0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) res+=count[i];
            //cout<<i<<" ";
        }  
        
        return res;
    }
