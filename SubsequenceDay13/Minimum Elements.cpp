// You have to tell the min no. of element you have to take to reach the target sum

// Memoization

#include <bits/stdc++.h> 
int f(int tar,int ind, vector<int>& curr, vector<vector<int>>& dp){
    if(ind==0){
        if(tar%curr[0]==0) return tar/curr[0];
        return 1e9;
    }
    
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    
    int notPick = 0 + f(tar,ind-1,curr,dp);
    int pick = INT_MAX;
    if(tar>=curr[ind]) pick = 1 + f(tar-curr[ind],ind,curr,dp);
    
    return dp[ind][tar] = min(pick,notPick);
    
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<vector<int>> dp(num.size(),vector<int>(x+1,-1));
    int ans = f(x,num.size()-1,num,dp);

    if(ans>=1e9) return-1;
    return ans;
}
