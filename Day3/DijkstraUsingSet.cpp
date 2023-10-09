{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        vector<bool> visited(V,false);
        
        // sorting will be done on basis of 1st argument
        st.insert({dist[S],S});
        
        while(!st.empty()){
            auto i= *(st.begin());
            int node = i.second;
            int d = i.first;
            st.erase(i);
            visited[node]=true;
            
            for(auto v : adj[node]){
    	    	int adjNode = v[0];
    	    	int edgeWeight = v[1];
    	    	
                if(dist[adjNode] > d + edgeWeight){
                    // erase if existed
                    if(dist[adjNode]!=INT_MAX){
                        st.erase({dist[adjNode],adjNode});
                    }
                    dist[adjNode] = d + edgeWeight;
                    st.insert({dist[adjNode],adjNode});
                }
            }   
        }
        return dist;
    }
};
