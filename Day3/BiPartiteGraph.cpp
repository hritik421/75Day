// Try to solve this using DFS

{
public:
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    vector<int> color(V,-1);
	    vector<bool> vis(V,false);
	    queue<int> q;
	    
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            q.push(i);
	            color[i]=0;
	            while(!q.empty()){
        	        int top = q.front();
        	        q.pop();
        	        for(int nbr:adj[top]){
        	            if(color[nbr]==-1){
        	                color[nbr]= !color[top];
        	                q.push(nbr);
        	                vis[nbr]=true;
        	            }
        	            else if(color[nbr]==color[top]) return false;
        	        }
	            }
	        }
	    }
	    return true;
	}

};
