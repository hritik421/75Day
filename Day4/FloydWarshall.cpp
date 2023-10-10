// Watch video again for more clarification

//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int row = matrix.size();
	    int col = matrix[0].size();
	    
	    for(int i=0;i<row;i++){
	        for(int j=0;j<col;j++){
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
