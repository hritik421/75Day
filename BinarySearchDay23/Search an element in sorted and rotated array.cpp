// Given a sorted and rotated array A of N distinct elements which are rotated at some point, and given an element K. 
// The task is to find the index of the given element K in array A.

int Search(vector<int> arr, int k) {
    //code here
    int low = 0, high = arr.size()-1;
    
    while(low<=high){
        int mid = low + (high-low)/2;
        if(arr[mid]==k) return mid;
        
        //step1: check which part is sorted
        if(arr[low]<=arr[mid]){
            // left part if sorted...
            if(arr[low]<=k && arr[mid]>=k){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else{
            // right part is sorted...
            if(arr[mid]<=k && arr[high]>=k){
                low = mid+1;
            }
            else high = mid-1;
        }
    }
    return -1;
}
