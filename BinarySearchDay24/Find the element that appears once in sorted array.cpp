// Given a sorted array arr[] of size N. Find the element that appears only once in the array. All other elements appear exactly twice. 

int findOnce(int arr[], int n)
    {
        //code here.
        int low=1,high=n-2;
        
        if(n==1) return arr[0];
        
        if(arr[0]!=arr[1]) return arr[0];
        
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1]) return arr[mid];
            
            // (even,odd) eliminate left side
            // (odd,even) eliminate right side
            if((mid%2==0 && arr[mid+1]==arr[mid]) ||(mid%2!=0 && arr[mid-1]==arr[mid])){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        
        return -1;
    }
