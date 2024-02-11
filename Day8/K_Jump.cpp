Link to Problem: https://atcoder.jp/contests/dp/tasks/dp_b

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
