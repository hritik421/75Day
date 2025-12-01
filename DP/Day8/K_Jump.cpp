// Link to Problem: https://atcoder.jp/contests/dp/tasks/dp_b
// https://www.codingninjas.com/studio/problems/frog-jump_3621012
// There is a frog on the '1st' step of an 'N' stairs long staircase. The frog wants to reach the 'Nth' stair. 
// 'HEIGHT[i]' is the height of the '(i+1)th' stair.If Frog jumps from 'ith' to 'jth' stair, the energy lost in the jump is given by absolute
// value of ( HEIGHT[i-1] - HEIGHT[j-1] ). If the Frog is on 'ith' staircase, he can jump either to '(i+1)th' stair or to '(i+2)th' stair. 
// Your task is to find the minimum total energy used by the frog to reach from '1st' stair to 'Nth' stair.

// For Example
// If the given ‘HEIGHT’ array is [10,20,30,10], the answer 20 as the frog can jump from 1st stair to 2nd stair (|20-10| = 10 energy lost) 
// and then a jump from 2nd stair to last stair (|10-20| = 10 energy lost). So, the total energy lost is 20.

// Sample Input 1
// 7 4 4 2 6 6 3 4 
// O/P: 7
// Sample Input 2
// 4 8 3 10 4 4 
// Sample Out: 2

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
