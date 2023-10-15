// Geek is going for n days training program, he can perform any one of these three activities Running, Fighting, and Learning Practice.
// Each activity has some point on each day. as Geek wants to improve all his skills, he can't do the same activity on two consecutive days,
// help Geek to maximize his merit points as we were given a 2D array of n*3 points corresponding to each day and activity.

// Memoization

class Solution {
  private:
    int DP(vector<vector<int>>& points, int n,int last, vector<vector<int>>& dp){
        if(n==0){
            int maxi=INT_MIN;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi = max(maxi,points[n][i]);
                }
            }
            return maxi;
        }
        
        if(dp[n][last]!=-1) return dp[n][last];
        
        //int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
                // int point = points[n][i] + DP(points,n-1,i,dp);
                // maxi = max(maxi,point);
                dp[n][last] = max(dp[n][last], points[n][i] + DP(points,n-1,i,dp));
            }
        }
        
        return dp[n][last];
    }
  public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,-1));
        return DP(points,n-1,3,dp);
    }
};

// Tabulation

public:
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<vector<int>> dp(n,vector<int>(4,0));
        // Base case for 1st iteration
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(max(points[0][1], points[0][2]),points[0][0]);
        
        
        for(int i=1;i<n;i++){
            for(int last=0;last<4;last++){
                for(int j=0;j<3;j++){
                    if(j!=last){
                        dp[i][last] = max(dp[i][last], points[i][j] + dp[i-1][j]);
                    }
                }
            }
        }
        
        return dp[n-1][3];
    }

// Space Optimization

int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        vector<int> prev(4,0);
        // Base case for 1st iteration
        prev[0] = max(points[0][1], points[0][2]);
        prev[1] = max(points[0][0], points[0][2]);
        prev[2] = max(points[0][1], points[0][0]);
        prev[3] = max(max(points[0][1], points[0][2]),points[0][0]);
        
        
        for(int i=1;i<n;i++){
            vector<int> temp(4,0);
            for(int last=0;last<4;last++){
                for(int j=0;j<3;j++){
                    if(j!=last){
                        temp[last] = max(temp[last], points[i][j] + prev[j]);
                    }
                }
            }
            prev = temp;
        }
        
        return prev[3];
    }
