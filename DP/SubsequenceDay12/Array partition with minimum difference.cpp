/*
https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
Space optimized

You are given an array 'arr' containing 'n' non-negative integers.
Your task is to partition this array into two subsets such that the absolute difference between subset sums is minimum.
You just need to find the minimum absolute difference considering any valid division of the array elements.

Logic is this in tabulation last row of dp array tell all the possible value from 0 to target. So by checking for true values we can 
find the minimum absolute difference.
*/

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

// for memoization need to call dp method for all target:
#include <bits/stdc++.h>
int solveDp(vector<int>& arr, int n, int tar, vector<vector<int>>& dp)
{
    if(n==0) return tar == arr[0];
    if(tar==0) return 1;

    if (dp[n][tar]!=-1) return dp[n][tar];

    bool pick = tar>=arr[n] ? solveDp(arr, n-1, tar-arr[n], dp): 0;
    bool notPick = solveDp(arr, n-1, tar, dp);

    return dp[n][tar] = pick || notPick;
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int sum = 0;
    for(int num: arr) sum+= num;

    int tar = sum/2 + 1;

    vector<vector<int>> dp(arr.size(), vector<int>(tar+1, -1));

    for(int i=1;i<=tar;i++) solveDp(arr, n-1, i, dp);

    int res = INT_MAX;

    for(int i=0;i<=tar;i++){
        if(dp[n-1][i]==1){
            res = min(res, abs(sum-2*i));
        }
    }

    return res;
}



