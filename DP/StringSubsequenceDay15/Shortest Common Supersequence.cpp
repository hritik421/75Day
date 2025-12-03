// Given two strings X and Y of lengths m and n respectively, find the length of the smallest string which has both, X and Y as its sub-sequences.
// Note: X and Y can have both uppercase and lowercase letters.

// Code for finding length

//Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        
        return n + m - dp[m][n];
    }

// Code for printing one of the possible supersequence
// Very important logic to print Longest common subsequence as well
.

// 🔥 Steps to Print the Shortest Common Supersequence

// Build the LCS table using DP

// Start from dp[m][n] and backtrack

// While backtracking:

// If characters match → include that character once in result

// If not, move in the direction of the bigger dp value (dp[i-1][j] vs dp[i][j-1])

// After backtracking, append the leftover characters of X or Y

// Reverse the result (because backtracking builds the string backwards)

#include <bits/stdc++.h> 
string shortestSupersequence(string X, string Y)
{
	// Write your code here.
	int m = X.size(), n = Y.size();
	vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(X[i-1]==Y[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

	string res="";

	while(m>0 && n>0){
		if(X[m-1] == Y[n-1]){
			res+=X[m-1];
			m--;
			n--;
		}
		else if(dp[m-1][n]>dp[m][n-1]){
			res+=X[m-1];
			m--;
		}
		else{
			res+=Y[n-1];
			n--;
		}
	}

	while(m>0) {
		res+=X[m-1];
		m--;
	}

	while(n>0){
		res+=Y[n-1];
		n--;
	}

	reverse(res.begin(),res.end());
    return res;
}
