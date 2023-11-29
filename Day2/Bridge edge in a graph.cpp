// Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., 
// removing the edge disconnects the graph

class Solution
{
    private:
    void dfs(int src, vector<int> adj[], int c, int d,vector<bool>& vis){
        vis[src]=true;
        
        for(int nbr:adj[src]){
            
            // We don't want the DFS traversal to consider the edge (c, d) while exploring other paths in the graph.
            if(nbr==d && src==c) continue;
            if(!vis[nbr]){
                dfs(nbr,adj,c,d,vis);
            }
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<bool> vis(V,false);
        dfs(c,adj,c,d,vis);
        if(vis[d]){
            return false;
        }
        return true;
    }
};
