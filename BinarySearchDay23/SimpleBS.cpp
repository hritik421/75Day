// Iterative approach

int binarysearch(int arr[], int n, int k) {
        // code here
        int low=0, high=n-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]==k) return mid;
            if(arr[mid]<k) low = mid+1;
            else high = mid-1;
        }
        
        return -1;
    }

// Recursive approach

private:
    int BS(int arr[],int low, int high, int tar){
        // Base condition
        if(low>high) return -1;
        
        int mid = low + (high-low)/2;
        
        if(arr[mid]==tar) return mid;
        if(arr[mid]<tar) return BS(arr,mid+1,high,tar);
        return BS(arr,low,mid-1,tar);
    }
  public:
    int binarysearch(int arr[], int n, int k) {
        // code here
        return BS(arr,0,n-1,k);
    }
