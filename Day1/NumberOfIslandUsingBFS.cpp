class Solution {
  public:
    // Function to find the number of islands.
    bool isValid(int x,int y,int n,int m){
        return (x>=0 && x<n && y>=0 && y<m);
    }
    
    void bfs(vector<vector<bool>>& visited,int i,int j,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        vector<int> dx={-1,-1,-1,0,0,1,1,1};
        vector<int> dy={-1,0,1,-1,1,-1,0,1};
        q.push({i,j});
        while(!q.empty()){
            int a= q.front().first;
            int b= q.front().second;
            q.pop();
            for(int k=0;k<8;k++){
                int n_x= a+ dx[k];
                int n_y= b+ dy[k];
                if(isValid(n_x,n_y,visited.size(),visited[0].size())){
                    if(grid[n_x][n_y]=='1' && !visited[n_x][n_y]){
                        visited[n_x][n_y]=true;
                        q.push({n_x,n_y});
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==false){
                    count++;
                    bfs(visited,i,j,grid);
                }
                    
            }
        }
        return count;
    }
};
