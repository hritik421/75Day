class Solution
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
            int d= i.first;
            visited[node]=true;
            
            for(auto v : adj[node]){
                if(visited[v[0]]==false){
                    if(dist[v[0]]> d + v[1]){
                        dist[v[0]] = d +v[1];
                        pq.push({dist[v[0]],v[0]});
                    }
                }
            }
            
        }
        return dist;
        
    }
};
