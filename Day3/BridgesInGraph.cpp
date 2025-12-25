class Solution {
private:
    int timer = 0;
    void dfs(vector<int> adj[], int low[], int disc[], vector<bool>& vis, int src, vector<vector<int>>& res, int parent){
        vis[src]=true;
        low[src]=disc[src]=timer++;

        for(int nbr:adj[src]){
            if(nbr==parent) continue;
            if(!vis[nbr]){
                dfs(adj,low,disc,vis,nbr,res,src);
                low[src]=min(low[src],low[nbr]);

                // check whether src and nbr is bridge
                if(low[nbr]>disc[src]){
                    res.push_back({src,nbr});
                }
            }
            else{
                low[src]=min(low[src],tin[nbr]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto i: connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int low[n];
        int disc[n];
        vector<bool> vis(n,false);
        vector<vector<int>> res;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,low,disc,vis,i,res,-1);
            }
        }

        return res;
    }
};
