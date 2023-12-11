// A sorted(in ascending order) array A[ ] with distinct elements is rotated at some unknown point, the task is to find the minimum element in it.

int findMin(int arr[], int n){
        //complete the function here
        int low=0,high=n-1,ans=INT_MAX;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[low]<=arr[mid]){
                //left part is sorted...
                ans=min(ans,arr[low]);
                low=mid+1;
            }else{
                ans=min(ans,arr[mid]);
                high = mid-1;
            }
        }
        
        return ans;
    }
