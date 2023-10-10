// Overview of algo:
// step1: Relax all the edge for n-1 times sequentially.
// What Relax means?
// meaning is -->  
// if((dist[u] + wt) < dist[v]){
//       dist[v] = dist[u] + wt;
// }
// Why N-1? 
// Since in a graph of n nodes, in worst case you will take n-1 edges to reach from the first to the last, there by we iterate for n-1 times.  
