//User function Template for C++
//The DFS root is an articulation point iff:
//It has more than one DFS child
// Different DFS children of root are in different connected components once root is removed.
class Solution {
    private:
    int timer = 1;
    void dfs(vector<int> adj[], int src, vector<int>& low, vector<int>& tin,vector<bool>& vis, int parent,vector<bool>& ap){
        vis[src]=true;
        tin[src]=low[src]=timer;
        timer++;
        int child=0;
        
        for(int nbr:adj[src]){
            
            if(nbr==parent)continue;
            
            if(!vis[nbr]){
                dfs(adj,nbr,low,tin,vis,src,ap);
                low[src]=min(low[src],low[nbr]);
                
                // now check for possinility of bridge
                if(tin[src]<=low[nbr] && parent!=-1){
                    ap[src]=true;
                }
                child++;
            }
            else{
                low[src]=min(low[src],tin[nbr]);
            }
        }
        
        if(child>1 && parent==-1){
            ap[src]=true;
        }
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> low(V,0);
        vector<int> tin(V,0);
        // do not declare vector<int> low; it will throw exception for low[src]=timer;
        vector<bool> vis(V,false);
        vector<bool> ap(V,false);
        vector<int> res;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(adj,i,low,tin,vis,-1,ap);
            }
        }
        
        
        for(int i=0;i<V;i++){
            if(ap[i]){
                res.push_back(i);
            }
        }
        
        if(res.size()==0) return {-1};
        return res;
    }
};
