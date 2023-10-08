class Solution
{
    private:
    
    void topoSort(vector<vector<int>>& adj,vector<bool>& vis, stack<int>& s, int src){
        vis[src]=true;
        for(int nbr: adj[src]){
            if(!vis[nbr]){
                topoSort(adj,vis,s,nbr);
            }
        }
        s.push(src);
    }
    
    void dfs(vector<vector<int>>& adj,vector<bool>& vis, int src){
        vis[src]=true;
        for(int nbr:adj[src]){
            if(!vis[nbr]){
                dfs(adj,vis,nbr);
            }
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<vector<int>> res(V);
        stack<int> st;
        vector<bool> vis(V, false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                topoSort(adj,vis,st,i);
            }
        }
        
        // step2: Reverse all edges of adj
        for(int i=0;i<V;i++){
            for(int nbr:adj[i]){
                res[nbr].push_back(i);
            }
        }
        
        //step3: Iterate using topo sort
        vector<bool> vis2(V,false);
        int count=0;
        while(!st.empty()){
            int top = st.top();
            st.pop();
            if(!vis2[top]){
                count++;
                dfs(res,vis2,top);
            }
        }
        
        return count;
        
    }
};
