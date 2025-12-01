// You are given a list of stock prices of size 'n' called ‘prices’, where ‘prices[i]’ represents the price on ‘i’th day.
// Your task is to calculate the maximum profit you can earn by trading stocks if you can only hold one stock at a time.
// After you sell your stock on the ‘i’th day, you can only buy another stock on ‘i + 2’ th day or later.
// Memoization

long long f(int ind, int buy, vector<long long>&prices, vector<vector<long long>>& dp){
        if(ind>=prices.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        
        long long profit = 0;
        if(buy){
            profit = max(-prices[ind] + f(ind+1,0,prices,dp), f(ind+1,1,prices,dp) );
        }
        else{
            profit = max( prices[ind] + f(ind+2,1,prices,dp), f(ind+1,0,prices,dp) );
        }
        
        return dp[ind][buy] = profit;
    }
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>> dp(n,vector<long long>(2,-1));
        return f(0,1,prices,dp);
    }

// Tabulation

long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<vector<long long>>dp(n+2,vector<long long>(2,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    dp[ind][buy] = max(-prices[ind] + dp[ind+1][0],
                                        dp[ind+1][1]);
                }
                else{
                    dp[ind][buy] = max(prices[ind] + dp[ind+2][1],
                                        dp[ind+1][0]);
                }
            }
        }
        
        return dp[0][1];
    }

// Space Optimized

long long maximumProfit(vector<long long>&prices, int n) {
        // Code here
        vector<long long>front1(2,0);
        vector<long long>front2(2,0);
        vector<long long>curr(2,0);
        
        
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if(buy){
                    curr[buy] = max(-prices[ind] + front1[0],
                                        front1[1]);
                }
                else{
                    curr[buy] = max(prices[ind] + front2[1],
                                        front1[0]);
                }
                front2 = front1;
                front1 = curr;
            }
        }
        
        return front1[1];
    }
