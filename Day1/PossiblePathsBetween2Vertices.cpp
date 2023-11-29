class Solution {
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        if(source==destination) return 1;
        queue<int> q;
        q.push(source);
        int count=0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            if(front==destination) count++;
            for(int i:adj[front]){
                q.push(i);
            }
        }
        
        return count;
    }
};

// Backtracking logic

visited[src] = true;
    if (src == dst) {
        path_count++;
    }
    // ...otherwise recurse into all neighbours...
    else {
        for (auto neighbour : m_neighbours[src]) {
            if (!visited[neighbour])
                path_counter(neighbour, dst, path_count,
                             visited);
        }
    }
    visited[src] = false;
