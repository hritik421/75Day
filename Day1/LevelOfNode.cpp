
class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    int res=0;
	    queue<pair<int,int> > q;
	    q.push({0,0});
	    vector<bool> visited(V,false);
	    while(!q.empty()){
	        auto temp=q.front();
	        q.pop();
	        if(temp.first==X) return temp.second;
	        for(int i : adj[temp.first]){
	            if(visited[i]==false) {
	                q.push({i,temp.second+1});
	                visited[i]=true;
	            }
	        }
	    }
	    return -1;
	}
};
