// Given a sequence of matrices, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// The dimensions of the matrices are given in an array arr[] of size N (such that N = number of matrices + 1) where the ith matrix has the dimensions (arr[i-1] x arr[i]).

// Input: N = 5
// arr = {40, 20, 30, 10, 30}
// Output: 26000
// Explanation: There are 4 matrices of dimension 
// 40x20, 20x30, 30x10, 10x30. Say the matrices are 
// named as A, B, C, D. Out of all possible combinations,
// the most efficient way is (A*(B*C))*D. 
// The number of operations are -
// 20*30*10 + 40*20*10 + 40*10*30 = 26000.

// Memoization

private:
    int f(int i, int j, int arr[], vector<vector<int>>& dp){
        //Only one matrix → cannot multiply → cost = 0
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans=INT_MAX;
        for(int k=i;k<j;k++){ 
            // arr[i-1], arr[k], arr[j] define the dimensions used in multiplying the result of left part (i..k) with right part (k+1..j).
            // Only 'k' changes; i and j fix the outer dimensions.
            int temp = arr[i-1]*arr[k]*arr[j] + f(i,k,arr,dp) + f(k+1,j,arr,dp);
            ans = min(ans,temp);
        }
        
        return dp[i][j]=ans;
    }
public:
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N,vector<int>(N,-1));
        return f(1,N-1,arr,dp);
    }
