// Coding Ninja question - https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0
//You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
//You need to figure out the total number of ways W, in which you can make a change for value V using coins of denominations from D. 
//Print 0, if a change isn't possible.
// NOTE: In this question order is important. if order is not there then we have to use loop for iterating over coins array

// Memoization

#include <bits/stdc++.h> 
int mod = 1e9+7;
long f(int tar,int ind, int *curr, vector<vector<long>> &dp){
    if(ind==0){
        return (tar%curr[0]==0);
    }
    
    if(dp[ind][tar]!=-1) return dp[ind][tar];
    
    long notPick = f(tar,ind-1,curr,dp);
    long pick = 0;
    if(tar>=curr[ind]) pick = f(tar-curr[ind],ind,curr,dp);
    
    return dp[ind][tar] = (pick + notPick);
    
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n,vector<long>(value+1,-1));
    return f(value, n-1, denominations,dp);
}
