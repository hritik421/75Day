Link to Problem: https://atcoder.jp/contests/dp/tasks/dp_b
https://www.codingninjas.com/studio/problems/frog-jump_3621012

class Solution {
  private:
    int Dp(int n, vector<int>& height, vector<int>& dp){
        if(n==0) return 0;
        
        if(dp[n]!=-1) return dp[n];
        
        int oneStep = Dp(n-1, height, dp) + abs(height[n] - height[n-1]);
        int twoStep = INT_MAX;
        if(n>1){
            twoStep = Dp(n-2, height, dp) + abs(height[n] - height[n-2]);
        }
        
        return dp[n] = min(oneStep, twoStep);
    }
  public:
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        
        vector<int> dp(n,0);
        int k=2;
        for(int i=1;i<n;i++){
            int minStep = INT_MAX;
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    int step = dp[i-j] + abs(height[i]-height[i-j]);
                    minStep = min(minStep,step);
                }
            }
            dp[i] = minStep;
        }
        return dp[n-1];
    }
};


Link to Problem: https://atcoder.jp/contests/dp/tasks/dp_b

#include <bits/stdc++.h> 
int dp(int n,vector<int> &heights, vector<int> &dip){
    if (n==0) return 0;
    if(dip[n]!=-1) return dip[n];
    int points = INT_MAX;
    for(int i=1;i<=2;i++){
        if(n-i>=0){
            points = min (points,abs(heights[n]-heights[n-i]) + dp(n-i,heights,dip));
        }
    }
    return dip[n] = points;
}
