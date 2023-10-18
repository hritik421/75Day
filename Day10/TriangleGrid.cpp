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

// Tabulation

int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<vector<int>> dp(n,vector<int>(n,0));

	for(int j=0;j<n;j++) dp[n-1][j] = triangle[n-1][j];

	for(int i=n-2;i>=0;i--){
		for(int j=i;j>=0;j--){
			int bottom = triangle[i][j] + dp[i+1][j];
			int diagnol = triangle[i][j] + dp[i+1][j+1];

			dp[i][j] = min(bottom, diagnol);
		}
	}

	return dp[0][0];
}

// Space Optimization


int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
	vector<int>prev(n,0);

	for(int j=0;j<n;j++) prev[j] = triangle[n-1][j];

	for(int i=n-2;i>=0;i--){
		vector<int> curr(n,0);
		for(int j=i;j>=0;j--){
			int bottom = triangle[i][j] + prev[j];
			int diagnol = triangle[i][j] + prev[j+1];

			curr[j] = min(bottom, diagnol);
		}
		prev = curr;
	}

	return prev[0];
}
