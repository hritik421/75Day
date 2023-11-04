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

// Tabulation 

long getMaximumProfit(long *values, int n)
{
    //Write your code here

    vector<vector<long>> dp(n+1,vector<long>(2,0));
    dp[n][0]=dp[n][1]=0;

    for(int ind = n-1; ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            long profit=0;
            if(buy){
                profit = max(-values[ind] + dp[ind+1][0],
                                0 + dp[ind+1][1]);
            }
            else{
                profit = max(values[ind] + dp[ind+1][1],
                                0 + dp[ind+1][0]);
            }

            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
}

// Sapce Optimization

long getMaximumProfit(long *values, int n)
{
    //Write your code here

    vector<long> ahead(2,0);
    ahead[0]=ahead[1]=0;

    for(int ind=n-1;ind>=0;ind--){
        vector<long> curr(2,0);
        for(int buy=0;buy<2;buy++){
            long profit=0;
            if(buy){
                profit = max(-values[ind] + ahead[0],
                                0 + ahead[1]);
            }
            else{
                profit = max(values[ind] + ahead[1],
                                0 + ahead[0]);
            }

            curr[buy] = profit;
        }
        ahead = curr;
    }
    return ahead[1];
}

// Using 4 variable instead ahead and curr vector

long getMaximumProfit(long *values, int n)
{
    //Write your code here

    long aheadBuy=0, aheadNotBuy=0, currBuy=0, currNotBuy=0;

    for(int ind=n-1;ind>=0;ind--){
        long profit=0;
        currBuy = max(-values[ind] + aheadNotBuy,
                        0 + aheadBuy);
        currNotBuy = max(values[ind] + aheadBuy,
                        0 + aheadNotBuy);
        aheadNotBuy = currNotBuy;
        aheadBuy = currBuy;
    }
    return aheadBuy;
}
