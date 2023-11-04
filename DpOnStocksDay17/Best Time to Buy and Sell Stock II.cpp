// Memoization

#include <bits/stdc++.h>
long f(int ind, int buy, long* values, vector<vector<long>>& dp,int n){
    if(ind==n) return 0;

    if(dp[ind][buy]!=-1) return dp[ind][buy];

    long profit=0;
    if(buy){
        profit = max(-values[ind] + f(ind+1,0,values,dp,n),
                        0 + f(ind+1,1,values,dp,n));
    }
    else{
        profit = max(values[ind] + f(ind+1,1,values,dp,n),
                        0 + f(ind+1,0,values,dp,n));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit(long *values, int n)
{
    //Write your code here
    // long ans = 0;

    // for(int i=1;i<n;i++){
    //     if(values[i]>values[i-1]){
    //         ans+=values[i]-values[i-1];
    //     }
    // }
    // return ans;

    vector<vector<long>> dp(n,vector<long>(2,-1));
    return f(0, 1, values, dp, n);
}
