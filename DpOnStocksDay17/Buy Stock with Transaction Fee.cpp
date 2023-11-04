// Memoization

long long f(int ind, int buy, vector<long long>& values, vector<vector<long long>>& dp,int n, int fee){
        if(ind==n) return 0;
    
        if(dp[ind][buy]!=-1) return dp[ind][buy];
    
        long long profit=0;
        
        if(buy){
            profit = max(-values[ind] + f(ind+1,0,values,dp,n,fee), f(ind+1,1,values,dp,n,fee));
        }
        else{
            profit = max(values[ind] - fee+ f(ind+1,1,values,dp,n,fee), f(ind+1,0,values,dp,n,fee));
        }
    
        return dp[ind][buy] = profit;
    }
    
    public:
    
    long long maximumProfit(vector<long long>&prices, int n, int fee) {
        // Code here
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return f(0,1,prices,dp,n,fee);
    }
