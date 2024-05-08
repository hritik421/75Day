// Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

// Note that the same word in the dictionary may be reused multiple times in the segmentation.
// Input: s = "applepenapple", wordDict = ["apple","pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
// Note that you are allowed to reuse a dictionary word.

class Solution {
public:
    bool helper(string s, unordered_set<string> words, vector<int>& dp, int start){
        if(s.size()==start) return 1;
        if(dp[start]!=-1) return dp[start];
        string temp;
        for(int i=start;i<s.size();i++){
            temp += s[i];
            if(words.find(temp)!=words.end()){
                if (helper(s, words, dp,i+1)){
                    return dp[start] = 1;
                }
            } 
        }
        return dp[start] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size()+1,-1);
        unordered_set<string> st;
        for(auto s:wordDict) st.insert(s);
        return helper(s, st,dp,0);
    }
};
