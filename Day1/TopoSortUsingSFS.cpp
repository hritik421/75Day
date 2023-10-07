{
    private:
    void dfs(int s, vector<bool>& vis, stack<int>& st, vector<int> adj[]){
        vis[s]= true;
        for(int i: adj[s]){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        st.push(s);
    }
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> res;
	    vector<bool> vis(V, false);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,vis,st,adj);
	        }
	    }
	    
	    while(!st.empty()){
	        res.push_back(st.top());
	        st.pop();
	    }
	    
	   
	    
	    return res;
	}
};
