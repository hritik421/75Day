// Memoization

int f(int ind, int buy, vector<int>& price, vector<vector<vector<int>>>& dp, int n, int cap){
    if(ind==n || cap==0) return 0;
    
    if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
    
    if(buy){
        return dp[ind][buy][cap] = max(-price[ind] + f(ind+1,0,price,dp,n,cap),
                                0 + f(ind+1,1,price,dp,n,cap));
    }
    
    return dp[ind][buy][cap] = max(price[ind] + f(ind+1,1,price,dp,n,cap-1),
                            0 + f(ind+1,0,price,dp,n,cap));
    
}

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp(n,vector<vector<int>>(2, vector<int>(3,-1)));
    return f(0,1,price,dp,n,2);
}

// Tabulation

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2, vector<int>(3,0)));
    
    // As we are returning 0 So base case covered already, if you want to write check below code
    // for ind ==n
    for(int buy=0;buy<2;buy++){
        for(int cap=0;cap<3;cap++){
            dp[n][buy][cap]=0;
        }
    }
    
    // for cap=0
    for(int ind=0;ind<=n;ind++){
        for(int buy;buy<2;buy++){
            dp[ind][buy][0]=0;
        }
    }
    
    // Iterate over all path
    
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            for(int cap=1;cap<3;cap++){
                if(buy){
                    dp[ind][buy][cap] = max(-price[ind] + dp[ind+1][0][cap],
                                            0 + dp[ind+1][1][cap]);
                }
                else{
                    dp[ind][buy][cap] = max(price[ind] + dp[ind+1][1][cap-1],
                                        0 + dp[ind+1][0][cap]);
                }
            }
        }
    }
    
    return dp[0][1][2];
}

// Space Optimization

int maxProfit(vector<int>&price){
    //Write your code here..
    int n = price.size();
    vector<vector<int>>ahead(2, vector<int>(3,0));
    vector<vector<int>>curr(2, vector<int>(3,0));
    
    // Iterate over all path
    
    for(int ind=n-1;ind>=0;ind--){
        for(int buy=0;buy<2;buy++){
            for(int cap=1;cap<3;cap++){
                if(buy){
                    curr[buy][cap] = max(-price[ind] + ahead[0][cap],
                                            0 + ahead[1][cap]);
                }
                else{
                    curr[buy][cap] = max(price[ind] + ahead[1][cap-1],
                                        0 + ahead[0][cap]);
                }
            }
        }
        ahead = curr;
    }
    
    return ahead[1][2];
}
