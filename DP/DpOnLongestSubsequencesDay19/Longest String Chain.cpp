// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.

class Solution {
  private:
  static bool cmp(string& s1, string& s2){
      return s1.size() < s2.size();
  }
  
  bool compareString(string& s1, string& s2){
      int n=s1.size(),m=s2.size();
      
      if(n != m+1) return false;
      
      int i=0,j=0;
      while(i<n){
          if(s1[i]==s2[j]){
              i++;
              j++;
          }
          else{
              i++;
          }
      }
      
      return i==n && j==m;
  }
  
  public:
    int longestChain(int n, vector<string>& words) {
        // Code here
        int maxi = 1;
        vector<int> dp(n,1);
        // to get the smallest string in 1st position
        sort(words.begin(),words.end(),cmp);
      
        // Alternative
        // sort(words.begin(),words.end(),[](string& s1, string& s2) {
        //                                 return s1.size() < s2.size();
        //                             });
      
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(compareString(words[i],words[j]) && dp[i]<1+dp[j]){
                    dp[i]=1+dp[j];
                    maxi=max(dp[i],maxi);
                }
            }
        }
        
        return maxi;
    }
};
