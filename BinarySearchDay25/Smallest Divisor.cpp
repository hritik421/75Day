// You are given an array of integers nums and an integer K, your task is to find the smallest positive integer divisor, such that upon dividing all the
// elements of the given array by it, the sum of the division's result is less than or equal to the given integer K.

private:
    bool isPossible(vector<int>& nums, int K, int d){
        int sum=0;
        for(int i:nums){
            sum+= (i/d + (i%d==0 ? 0 : 1));
        }
        return sum<=K;
    }
  public:
    int smallestDivisor(vector<int>& nums, int K) {

        // Write your code here.
      //Catch here is to start low with 1
        int low=1, high=INT_MIN;
        
        for(int i:nums){
            high = max(high,i);
        }
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(isPossible(nums,K,mid)){
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return low;
    }
