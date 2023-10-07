

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool isValid(int i,int j,int n,int m){
        return (i>=0 && i<n && j>=0 && j<m);
    }
    bool is_Possible(vector<vector<int>>& grid) 
    {
        //code here
        int n= grid.size();
        vector<int> dx={-1,0,1,0};
        vector<int> dy={0,1,0,-1};
        queue<pair<int,int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        
        while(!q.empty()){
            int i= q.front().first;
            int j= q.front().second;
            q.pop();
            
            if(grid[i][j]==2) return true;
            for(int k=0;k<4;k++){
                int n_x= i+ dx[k];
                int n_y= j+ dy[k];
                if(isValid(n_x,n_y,n,n) && grid[n_x][n_y]==3){
                    grid[n_x][n_y]=1;
                    q.push({n_x,n_y});
                }
                if(isValid(n_x,n_y,n,n)&& grid[n_x][n_y]==2) return true;
            }
        }
        return false;
    }
};
