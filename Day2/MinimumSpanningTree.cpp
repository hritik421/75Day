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
