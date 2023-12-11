// Given a sorted and rotated array A of N elements which is rotated at some point, and may contain duplicates and given an element key. Check whether the key exist in the array A or not.

bool Search(int N, vector<int>& A, int Key) {
        // Code here
        int low=0, high = A.size()-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(A[mid]==Key) return true;
            
            if(A[mid]==A[low] && A[mid]==A[high]){
                low++;
                high--;
                continue;
            }
            
            //Find which part is sorted
            if(A[low]<=A[mid]){
                //left part is sorted...
                if(A[low]<=Key && Key<=A[mid]){
                    high=mid-1;
                }else{
                    low=mid+1;
                }
            }
            else{
                //Right part is sorted...
                if(A[mid]<=Key && Key<=A[high]){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
