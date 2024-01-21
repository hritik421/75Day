// Given a grid of dimension nxm where each cell in the grid can have values 0, 1 or 2 which has the following meaning:
// 0 : Empty cell
// 1 : Cells have fresh oranges
// 2 : Cells have rotten oranges

// We have to determine what is the earliest time after which all the oranges are rotten. A rotten orange at index [i,j] can rot other
// fresh orange at indexes [i-1,j], [i+1,j], [i,j-1], [i,j+1] (up, down, left and right) in unit time. 
{
    public:
    
     bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here// Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    vector<vector<bool> > vis(n,vector<bool>(m,false));
	    
	    vector<int> dx={-1,0,1,0};
	    vector<int> dy={0,1,0,-1};
	    int ans = 0;
	    queue<pair<pair<int,int>,int>> q;
	    
	    int countFresh = 0;
	    for(int i=0;i<n;i++){
	        vector<int> curr;
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==2){
	                q.push({{i,j},0});
	                vis[i][j]=true;
	            }
	            if(grid[i][j]==1) countFresh++;
	        }
	    }
	    
	    int rottedFreshCount = 0;
	   while(!q.empty()){
	       int i= q.front().first.first;
	       int j= q.front().first.second;
	       int timer = q.front().second;
	       ans=max(ans,timer);
	       q.pop();
	       
	       for(int k=0;k<4;k++){
	           
	           int n_x= i + dx[k];
	           int n_y= j + dy[k];
	           
	           if(isValid(n_x,n_y,n,m) && !vis[n_x][n_y] && grid[n_x][n_y]==1){
	               vis[n_x][n_y]= true;
	               grid[n_x][n_y]=2;
	               rottedFreshCount++;
	               q.push({{n_x,n_y},timer+1});
	           }
	       }
	   }
	   
	   if(rottedFreshCount==countFresh) return ans;
	   return -1;     
    }
};
