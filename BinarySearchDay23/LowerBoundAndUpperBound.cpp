// STL way to use
int ind = lower_bound(arr.begin(),arr.end(),n) - arr.begin();
int und = upper_bound(arr.begin(),arr.end(),n) - arr.begin();


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
