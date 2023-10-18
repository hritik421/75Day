// Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

// Matrix [r+1] [c]
// Matrix [r+1] [c-1]
// Matrix [r+1] [c+1]
// Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

// NOTE: We can start from any column in zeroth row and can end at any column in (N-1)th row.

// Memoization

class Solution{
private:
    int f(int i, int j, int n, vector<vector<int>> Matrix, vector<vector<int>>& dp){
        if(j<0 || j>=n) return -1e8;
        if(i==0) return Matrix[i][j];
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int s = Matrix[i][j] + f(i-1,j,n,Matrix,dp);
        int ld = Matrix[i][j] + f(i-1,j-1,n,Matrix,dp);
        int rd = Matrix[i][j] + f(i-1,j+1,n,Matrix,dp);
        
        return dp[i][j] = max(s,max(ld,rd));
    }
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int maxi = -1e8;
        vector<vector<int>> dp(N, vector<int>(N,-1));
        for(int i=0;i<N;i++){
            maxi = max(maxi, f(N-1,i,N,Matrix,dp));
        }
        return maxi;
    }
};

// Tabulation

int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        int maxi = -1e8;
        
        vector<vector<int>> dp(N, vector<int>(N,0));
        
        for(int i=0;i<N;i++) dp[0][i] = Matrix[0][i];
        
        for(int i=1;i<N;i++){
            for(int j=0;j<N;j++){
                
                int s = Matrix[i][j] + dp[i-1][j];
                int ld = Matrix[i][j];
                
                if(j-1>=0) ld += dp[i-1][j-1];
                else ld += -1e9;
                
                int rd = Matrix[i][j];
                
                if(j+1<N) rd +=  dp[i-1][j+1];
                else rd += -1e9;
                
                dp[i][j] = max(s,max(ld,rd));
            }
        }
        
        for(int i=0;i<N;i++) maxi = max(maxi, dp[N-1][i]);
        
        return maxi;
    }
