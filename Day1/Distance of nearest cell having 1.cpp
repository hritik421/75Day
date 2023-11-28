// Given a binary grid of n*m. Find the distance of the nearest 1 in the grid for each cell.
// The distance is calculated as |i1  - i2| + |j1 - j2|, where i1, j1 are the row number and column number of the current cell, and i2, j2 
// are the row number and column number of the nearest cell having value 1. There should be atleast one 1 in the grid.

class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }

	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<int> > res(n,vector<int>(m,-1));
	    
	    vector<int> dx={-1,0,1,0};
	    vector<int> dy={0,1,0,-1};
	    int ans = INT_MAX;
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<n;i++){
	        vector<int> curr;
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                res[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
    
	   while(!q.empty()){
	       int i= q.front().first;
	       int j= q.front().second;
	       
	       q.pop();
	       for(int k=0;k<4;k++){
	           
	           int n_x= i + dx[k];
	           int n_y= j + dy[k];
	           
	           if(isValid(n_x,n_y,n,m) && res[n_x][n_y]==-1){
	               res[n_x][n_y]= res[i][j]+1;
	               q.push({n_x,n_y});
	           }
	       }
	   }
	    return res;      
	}
};
