// Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing two integers
// where the first integer of each list j denotes there is edge between i and j , second integers corresponds to the weight of that  edge . 
// You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S.
// You have to return a list of integers denoting shortest distance between each node and Source vertex S.
 
// Note: The Graph doesn't contain any negative weight cycle.

{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        vector<bool> visited(V,false);
        
        // sorting will be done on basis of 1st argument
        pq.push({dist[S],S});
        
        while(!pq.empty()){
            auto i= pq.top();
            pq.pop();
            int node = i.second;
            int d = i.first;
            visited[node]=true;
			
            // Most Imp check, it can be ask in interview
            if(dist[node] < d) continue;
			
            for(auto v : adj[node]){
    	    	int adjNode = v[0];
    	    	int edgeWeight = v[1];
                if(dist[adjNode] > d + edgeWeight){
                    dist[adjNode] = d + edgeWeight;
                    pq.push({dist[adjNode],adjNode});
                }
            }   
        }
        return dist;
    }
};

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> dist(V, INT_MAX);
        
        vector<vector<int>> adj[V];
        vector<bool> vis(V, false);
        for (auto &e : edges) {
            int u = e[0];
            int v = e[1];
            int w = e[2];
        
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // undirected graph
        }
        
        pq.push({0, src});
        dist[src]=0;
        
        while(pq.empty()==false){
            int w = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            vis[currNode] = true;
            
            // Most Imp check, it can be ask in interview
            if(dist[currNode] < w) continue;
            
            for(auto nbr: adj[currNode]){
                int nbrNode = nbr[0];
                int distToNbr = nbr[1];
                
                if(vis[nbrNode]==false && dist[nbrNode]> distToNbr + dist[currNode]){
                    dist[nbrNode] = distToNbr + dist[currNode];
                    pq.push({dist[nbrNode], nbrNode});
                }
            }
        }
        
        return dist;
    }
};
