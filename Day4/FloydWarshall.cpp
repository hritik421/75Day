// Watch video again for more clarification
// Key points:
// 1. It is for finding shortest path from any source to any destination, it is like multi source
// 2. In finding shortest we use the adjacency matrix instead of adj list
// 3. If graph is undirected, while creating adj matrix put same value for both adj[u][v] = adj[v][u] = x;
// 4. This algo helps in detecting negative weight cycle as well,
// if cost to reach node itself is negative that means negative weight cycle is there because cost to reach node itself is 0.

// Note: Algo like dijstra or bellman ford are single source shortest path algo

//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int row = matrix.size();
	    int col = matrix[0].size();
	    
	    for(int i=0;i<row;i++){
	        for(int j=0;j<col;j++){
				// where path is not exist
	            if(matrix[i][j]==-1) matrix[i][j] = 1e8;
	        }
	    }
	    
	    for(int via=0;via<row;via++){
	        for(int i=0;i<row;i++){
    	        for(int j=0;j<col;j++){
    	            if(matrix[i][j] > (matrix[i][via] + matrix[via][j])){
    	                matrix[i][j] = (matrix[i][via] + matrix[via][j]);
    	            }
    	        }
	        }
	    }
	    
	    for(int i=0;i<row;i++){
	        for(int j=0;j<col;j++){
	            if(matrix[i][j]==1e8) matrix[i][j] = -1;
	        }
	    }
	}
};
