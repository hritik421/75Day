// https://leetcode.com/problems/maximum-difference-score-in-a-grid/description/
// You are given an m x n matrix grid consisting of positive integers. You can move from a cell in the matrix to any other cell that is either to the bottom or to the right (not necessarily adjacent). The score of a move from a cell with the value c1 to a cell with the value c2 is c2 - c1.

// You can start at any cell, and you have to make at least one move.

// Return the maximum total score you can achieve.

class Solution {
public:

    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> smallest(n+1, vector<int>(m+1,0));
        int minDiffIfAllDesc = INT_MIN;
        bool allDesc = true;
        // calculate smallest value for 1st row
        smallest[0][0] = grid[0][0];
        for(int col=1;col<m;col++){
            if(allDesc && grid[0][col]>=smallest[0][col-1]){
                allDesc = false;
            }else if(allDesc){
                minDiffIfAllDesc = max(minDiffIfAllDesc, grid[0][col] - smallest[0][col-1]);
            }
            smallest[0][col] = min(smallest[0][col-1],grid[0][col]);
        }

        //calculate smallest for 1st col
        for(int row=1;row<n;row++){
            if(allDesc && grid[row][0]>=smallest[row-1][0]){
                allDesc = false;
            }else if(allDesc){
                minDiffIfAllDesc = max(minDiffIfAllDesc, grid[row][0]-smallest[row-1][0]);
            }
            smallest[row][0] = min(smallest[row-1][0], grid[row][0]);
        }

        // Now update smallest for rest of the matrix
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                // step1 update smallest from it top and left
                smallest[i][j] = min(smallest[i-1][j], smallest[i][j-1]);
                //check for all desc
                if(allDesc && smallest[i][j]<=grid[i][j]) allDesc = false;
                else if(allDesc) minDiffIfAllDesc = max(minDiffIfAllDesc, grid[i][j]-smallest[i][j]);
                // step2: check smallest for current value of grid
                smallest[i][j] = min(smallest[i][j], grid[i][j]);
            }
        }

        if(allDesc) return minDiffIfAllDesc;

        int res = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res = max(res, grid[i][j] - smallest[i][j]);
            }
        }
        return res;
    }
};
