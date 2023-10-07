// What is Mother Vertes?
// A Mother Vertex is a vertex through which we can reach all the other vertices of the Graph.
// Note:  If there is more than one possible nodes then return the node with minimum value.

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
    void dfs(int V,int src, vector<int>adj[],int &count,vector<bool>& visited){
        visited[src]=true;
        count++;
        for(int v: adj[src]){
            if(visited[v]==false){
               dfs(V,v,adj,count,visited); 
            }
        }
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code hereint 
	    for(int i=0;i<V;i++){
	        int count=0;
	        vector<bool> visited(V,false);
	        dfs(V,i,adj,count,visited);
	        if(count == V) return i;
	    }
	    return -1;
	}
};
