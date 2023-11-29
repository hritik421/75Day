// Given a weighted, undirected and connected graph of V vertices and E edges. The task is to find the sum of weights of the edges of the Minimum 
// Spanning Tree. Given adjacency list adj as input parameters . Here adj[i] contains vectors of size 2, where the first integer in that 
// vector denotes the end of the edge and the second integer denotes the edge weight

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	    int spanningTree(int V, vector<vector<int>> adj[])
	    {
	        // code here
	        vector<bool> mst(V,false); 
	        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	        int res=0;
	        pq.push({0,0});
	        
	        while(!pq.empty()){
	            int w = pq.top().first;
	            int v = pq.top().second;
	            pq.pop();
	            if(mst[v]) continue;
	            mst[v]=true;
	            res+=w;
	            for(auto i:adj[v]){
	                if(!mst[i[0]]){
	                    pq.push({i[1], i[0]});
	                }
	            }
	        }
	        
	        return res;
	    }
};


// Solution: 2

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	    int spanningTree(int V, vector<vector<int>> adj[])
	    {
	        // code here
	        vector<int> res(V,INT_MAX);
	        vector<bool> vis(V,false);
	        res[0] = 0;
	        vis[0] = true;
	        priority_queue<pair<int,int>, vector<pair<int,int>>, greater <pair<int,int>>> pq;
	        
	        pq.push({0,0});
	        
	        while(!pq.empty()){
	            auto i = pq.top();
	            pq.pop();
	            int front = i.second;
	            int w = i.first;
	            vis[front] = true;
	            
	            for(auto v : adj[front]){
	                if(!vis[v[0]] && res[v[0]]> (v[1])){
	                    res[v[0]] = v[1];
	                    pq.push({res[v[0]],v[0]});
	                }
	            }
	        }
	        
	        int ans = 0;
	        for(int i=0; i<res.size();i++){
	            ans += res[i];
	            //cout<<res[i];
	        }
	        return ans;
	    }
};
