// Memoization

#include <bits/stdc++.h> 
int f(int n, int m,int last, vector<vector<int>>& triangle, vector<vector<int>>& dp){
	if(n==last){
		return triangle[n][m];
	}

	if(dp[n][m]!=1e7+7) return dp[n][m];

	int bottom = triangle[n][m] + f(n+1,m,last,triangle,dp);
	int diagnol = triangle[n][m] + f(n+1,m+1,last,triangle,dp);

	return dp[n][m] = min(bottom,diagnol);
}

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n,1e7+7));
	return f(0,0,n-1,triangle,dp);
}
