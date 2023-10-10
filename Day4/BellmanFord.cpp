// Overview of algo:
// step1: Relax all the edge for n-1 times sequentially.
// What Relax means?
// meaning is -->  
// if((dist[u] + wt) < dist[v]){
//       dist[v] = dist[u] + wt;
// }
// Why N-1? 
// Since in a graph of n nodes, in worst case you will take n-1 edges to reach from the first to the last, there by we iterate for n-1 times.  

// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V,1e8);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(auto edge:edges){
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                
                if(dist[v]> (w + dist[u])){
                    dist[v] = w + dist[u];
                }
            }
        }
        
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dist[v]> (w + dist[u])){
                return {-1};
            }
        }
        
        return dist;
    }
};
