// You are given N balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array arr. You are asked to burst all the balloons.
// If you burst the ith balloon, you will get arr[ i - 1 ] * arr[ i ] * arr[ i + 1] coins. If i - 1, or i + 1 goes out of the bounds of the array, consider it as if there is a balloon with a 1 painted on it.
// Return the maximum coins you can collect by bursting the balloons wisely.

// Memoization

private:
    int f(int i, int j, vector<int> &arr, vector<vector<int>>& dp){
        if(i>j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int maxi = INT_MIN;
        
        for(int ind=i;ind<=j;ind++){
            // Draw bottom up diagram to understand the formula
            int cost = arr[i-1]*arr[ind]*arr[j+1] + f(i,ind-1,arr,dp) + f(ind+1,j,arr,dp);
            maxi = max(cost,maxi);
        }
        
        return dp[i][j] = maxi;
        
    }
public:
    int maxCoins(int N, vector<int> &arr) {
        // code here
        arr.insert(arr.begin(),1);
        arr.push_back(1);
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return f(1,N,arr,dp);
    }
