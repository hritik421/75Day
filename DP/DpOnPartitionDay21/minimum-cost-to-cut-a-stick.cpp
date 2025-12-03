//https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

class Solution {
public:
    int solveDp(int start, int end, vector<int>& cuts, vector<vector<int>>& dp)
    {
        if(start>end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];
        int ans = INT_MAX;
        for(int k=start; k<=end; k++){
            int temp = (cuts[end+1] - cuts[start-1]) + solveDp(start, k-1, cuts, dp) + solveDp(k+1, end, cuts, dp);
            ans = min(temp, ans);
        }

        return dp[start][end] = ans;
    }

    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        // sort so that partition do not overlap 
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int>(cuts.size(), -1));
        return solveDp(1, cuts.size()-2, cuts, dp);
    }
};
