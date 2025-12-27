//https://www.geeksforgeeks.org/problems/maximum-connected-group/1

//You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. 
//You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. 
//Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

// User function Template for C++
class DisjointSet{
  public:
  vector<int>parent,size;
  DisjointSet(int n){
    parent.resize(n);
    size.resize(n,1);
    for(int i=0;i<n;i++){
      parent[i] = i;
    }
  }
  int findUpar(int node){
    if(parent[node] == node){
      return node;
    }
    return parent[node] = findUpar(parent[node]);
  }
  void unionbysize(int u,int v){
    int ulp_u = findUpar(u);
    int ulp_v = findUpar(v);
    if(ulp_u == ulp_v){
      return;
    }
    if(size[ulp_u] <= size[ulp_v]){
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }else{
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
       int n = grid.size();
        vector<int>delrow = {-1,0,1,0};
        vector<int>delcol = {0,1,0,-1};
        DisjointSet ds(n*n);
        //step 1 - join current islands
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j] == 0){
              continue;
            }
            for(int k=0;k<4;k++){
              int nrow = i + delrow[k];
              int ncol = j + delcol[k];
              if(nrow >=0 && ncol >=0 && nrow < n && ncol < n && grid[nrow][ncol] == 1){
                int curr_node = i * n + j;
                int adjNode = nrow * n + ncol;
                ds.unionbysize(curr_node,adjNode);
              }
            }
          }
        }
        // step2 : check size and store it
        int mx = 0;
        for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
            if(grid[i][j] == 1){
              continue;
            }
            set<int>adjComponents;
            for(int k=0;k<4;k++){
              int nrow = i + delrow[k];
              int ncol = j + delcol[k];
              if(nrow >=0 && ncol >=0 && nrow < n && ncol < n && grid[nrow][ncol] == 1){
                int adjNode = nrow * n + ncol;
                adjComponents.insert(ds.findUpar(adjNode));
              }
            }
            int total = 0;
            for(auto it:adjComponents){
              total += ds.size[it];
            }
            mx = max(mx,total+1); // + 1 because we have to include curr cell with 0 also.
          }
        } 
    
        // what if all the cells are 1
        for(int i=0;i<n*n;i++){
        //   cout<<ds.size[ds.findUpar(i)]<<" ";
          mx = max (mx,ds.size[ds.findUpar(i)]);
        }
        return mx;
    }
};
