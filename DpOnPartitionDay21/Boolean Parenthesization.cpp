// Given a boolean expression S of length N with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Note: The answer can be large, so return it with modulo 1003

// Memoization

int mod = 1003;

class Solution{
private:
    int f(int i, int j, bool isTrue, string S, vector<vector<vector<int>>>& dp){
        if(i>j) return 0;
        
        if(i==j){
            if(isTrue) return S[i] == 'T';
            else return S[i] == 'F';
        }
        
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        
        int ways=0;
        for(int ind=i+1;ind<j;ind+=2){
            
            int lT = f(i,ind-1,true,S,dp);
            int lF = f(i,ind-1,false,S,dp);
            int rT = f(ind+1,j,true,S,dp);
            int rF = f(ind+1,j,false,S,dp);
            
            if(S[ind]=='&'){
                if(isTrue) ways = (ways + (rT*lT)%mod) % mod;
                else ways = (ways + (rT*lF)%mod + (rF*lT)%mod + (rF*lF)%mod)%mod;
            }
            else if(S[ind]=='|'){
                if(isTrue) ways = (ways + (rT*lF)%mod + (rF*lT)%mod + (rT*lT)%mod)%mod;
                else ways = (ways + (rF*lF)%mod) % mod;
            }
            else{
                if(isTrue) ways = (ways + (rT*lF)%mod + (rF*lT)%mod)%mod;
                else ways = (ways + (rT*lT)%mod + (lF*rF)%mod)%mod;
            }
        }
        
        return dp[i][j][isTrue] = ways;
    }
public:
    int countWays(int N, string S){
        // code here
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(N,vector<int>(2,-1)));
        return f(0,N-1,true,S,dp);
    }
