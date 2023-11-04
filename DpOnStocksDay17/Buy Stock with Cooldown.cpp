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
