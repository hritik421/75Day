{
    private:
    
    bool isValid(int x,int y,int n,int m){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis,
    int a, int b){
        int x= a;
        int y= b;
        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={-1,0,1,-1,1,-1,0,1};
        //q.pop();
        vis[x][y]= true;
        for(int i=0;i<8;i++){
            int a=x+dx[i];
            int b=y+dy[i];
            if(isValid(a,b,grid.size(),grid[0].size()) && grid[a][b]=='1' && !vis[a][b]){
                dfs(grid,vis,a,b);
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={-1,0,1,-1,1,-1,0,1};
        int row = grid.size();
        int col = grid[0].size();
        int count=0;
        vector<vector<bool>> vis(row, vector<bool>(col, false));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,vis,i,j);
                }
            }
        }
        
        return count;
        
    }
};
