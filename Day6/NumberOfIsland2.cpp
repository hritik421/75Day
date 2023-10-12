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

class Solution {
    private: 
        bool isValid(int x, int y, int n, int m){
            return x>=0 && y>=0 && x<n && y<m;
        }
    
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(m*n);
        vector<int> res;
        vector<vector<int>> mat(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<operators.size();i++){
            int row = operators[i][0];
            int col = operators[i][1];
            int node = row*m + col;
            if(mat[row][col]==1) res.push_back(count);
            else{
                count++;
                mat[row][col]=1;
                vector<int> dr = {-1,0,1,0};
                vector<int> dc = {0,1,0,-1};
                for(int ind=0;ind<4;ind++){
                    int nRow = row + dr[ind];
                    int nCol = col + dc[ind];
                    if(isValid(nRow,nCol,n,m)){
                        if(mat[nRow][nCol]==1 && ds.findUltParent(node)!= ds.findUltParent(nRow*m+nCol)){
                            count--;
                            ds.unionBySize(node,nRow*m+nCol);
                        }
                    }
                }
                res.push_back(count);
            }
        }
        return res;
    }
};
