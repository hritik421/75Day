// User function Template for C++
class DisjointSet{
    public:
    vector<int> parent, size, rank;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        
        for(int i=0;i<n+1;i++) parent[i]=i;
    }
    
    int findUltParent(int node){
        if(parent[node]==node){
            return node;
        }
        
        return parent[node] = findUltParent(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int pv = findUltParent(v);
        int pu = findUltParent(u);
        
        if(pv == pu) return;
        if(size[pv]>size[pu]){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pu];
        }
        
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        
        int extraEdge = 0;
        int numOfComponent = 0;
        DisjointSet d(n);
        for(auto e:edge){
            int u = e[0];
            int v = e[1];
            int pv = d.findUltParent(v);
            int pu = d.findUltParent(u);
            
            if(pv==pu){
                extraEdge++;
            }
            else {
                d.unionBySize(u,v);
            }
        }
        
        for(int i=0;i<n;i++){
            if(d.parent[i]==i) numOfComponent++;
        }
        
        if(numOfComponent-1<=extraEdge) return numOfComponent-1;
        return -1;
    }
};
