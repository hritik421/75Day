// STL way to use
int ind = lower_bound(arr.begin(),arr.end(),n) - arr.begin();
int und = upper_bound(arr.begin(),arr.end(),n) - arr.begin();

//Note: finding ceil == lower_bound();
// implementation

int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int low=0,high=n-1,ans=n;

	while(low<=high){
		int mid = low + (high-low)/2;
		// for upper bound just remove equalto sign
		if(arr[mid]>=x){
			ans = mid;
			high=mid-1;
		}
		else{
			low = mid+1;
		}
	}

	return ans;
}

// Floor
// Given a sorted array arr[] of size N without duplicates, and given a value x. Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x. 
// Find the index of K(0-based indexing).

int findFloor(vector<long long> v, long long n, long long x){
        
        // Your code here
        long long low =0,high=n-1,ans=n;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(v[mid]<=x){
                ans=mid;
                low = mid+1;
            }
            else high = mid - 1;
        }
        return ans==n?-1:ans;
        
    }
