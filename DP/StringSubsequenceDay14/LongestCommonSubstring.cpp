//Given two strings. The task is to find the length of the longest common substring.


// Find its Memoization code

// Tabulation

int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int ans =0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                // important i-1 because we have shifted index by 1
                if(S1[i-1]==S2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                    ans = max(ans,dp[i][j]);
                }
            }
        }
        
        return ans;
    }

// Memoization

int dp[1001][1001];
int ans = 0;

int f(string &s1, string &s2, int i, int j) {
    if (i < 0 || j < 0) return 0;

    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j]) {
        dp[i][j] = 1 + f(s1, s2, i - 1, j - 1);
        ans = max(ans, dp[i][j]);
        return dp[i][j];
    }

    // If characters mismatch, substring breaks
    return dp[i][j] = 0;
}

int longestCommonSubstring(string s1, string s2) {
    memset(dp, -1, sizeof(dp));
    ans = 0;

    int n = s1.length();
    int m = s2.length();

    // Check all ending positions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            f(s1, s2, i, j);
        }
    }

    return ans;
}
