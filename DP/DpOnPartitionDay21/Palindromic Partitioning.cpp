// Given a string str, a partitioning of the string is a palindrome partitioning if every sub-string of the partition is a palindrome. 
// Determine the fewest cuts needed for palindrome partitioning of the given string

// Memoization

private:

    bool isPalindrome(int i, int j, string s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    
    int f(int i, int n, string s, vector<int>& dp){
        
        if(i==n) return 0;
        
        if(dp[i]!=-1) return dp[i];
        int ans = INT_MAX;
        
        for(int j=i;j<n;j++){
            if(isPalindrome(i,j,s)){
                int cost = 1 + f(j+1,n,s,dp);
                ans = min(cost,ans);
            }
        }
        
        return dp[i] = ans;
    }
public:
    int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n,-1);
        
        // -1 we are doing because it do partition in the end. for eg: A|B|C| after c vaala minus kr rhe hai
        return f(0,n,str,dp) - 1;
    }

// Tabulation

int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int> dp(n+1,0);
        
        // Base Case
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--){
            int ans = INT_MAX;
        
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,str)){
                    int cost = 1 + dp[j+1];
                    ans = min(cost,ans);
                }
            }
            
            dp[i] = ans;
        }
        
        // -1 we are doing because it do partition in the end. for eg: A|B|C| after c vaala minus kr rhe hai
        return dp[0] - 1;
    }
