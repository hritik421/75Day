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
    
    void unionByRank(int u, int v){
        int pv = findUltParent(v);
        int pu = findUltParent(u);
        
        if(pv == pu) return;
        
        if(rank[pv]==rank[pu]){
            parent[pu]=pv;
            rank[pv]++;
        }
        else if(rank[pv]>rank[pu]){
            parent[pu]=pv;
        }
        else{
            parent[pv]=pu;
        }
    }
};
