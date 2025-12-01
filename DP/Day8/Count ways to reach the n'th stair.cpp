// Ques: There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. 
//   Count the number of ways, the person can reach the top (order does matter)

// Approach 1:

private: 
        int Dp(int n, vector<int>&dp){
            
            if(n==0 || n==1) return 1;
            if(dp[n]!=-1) return dp[n];
            
            return dp[n] = (Dp(n-1,dp) + Dp(n-2,dp))%1000000007;
            
        }
        
public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code here
        
        vector<int> dp(n+1,-1);
        return Dp(n,dp);
    }


// Approach2: Space optimized

class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
    int countWays(int n)
    {
        // your code 
        int prev = 1;
        int prev2= 1;
        
        int res;
        for(int i=2;i<n+1;i++){
            res = (prev + prev2)%1000000007;
            prev2 = prev;
            prev = res;
        }
        return res;
    }
};
