// To make one bouquet we need K adjacent flowers from the garden. Here the garden consists of N different flowers, the ith flower will bloom
// in the bloomDay[i]. Each flower can be used inside only one bouquets. We have to find the minimum number of days need to wait to make M
// bouquets from the garden. If we cannot make m bouquets, then return -1.

bool isPossible(int m,int k, vector<int> &bloomDay, int day){
        int count=0;
        int ans=0;
        for(int i:bloomDay){
            if(count==k){
                count=0;
                ans++;
            }
            if(day>=i){
                count++;
            }else{
                count=0;
            }
        }
        if(count==k)ans++;
        return ans>=m;
    }
    
    int solve(int M, int K, vector<int> &bloomDay){
      // Code here
      if(M*K > bloomDay.size()) return -1;
      int low=INT_MAX,high=INT_MIN;
      for(int i:bloomDay){
          low=min(low,i);
          high=max(high,i);
      }
      
      while(low<=high){
          int mid = low + (high-low)/2;
          if(isPossible(M,K,bloomDay,mid)) {
              high=mid-1;
          }
          else{
              low=mid+1;
          }
      }
      return low;
    }
