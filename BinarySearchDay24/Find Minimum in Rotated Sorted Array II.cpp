// Duplicate values are present in array

class Solution {
public:
    int findMin(vector<int>& arr) {
        int low=0,high=arr.size()-1;
        int ans=INT_MAX;

        while(low<=high){
            int mid = low + (high-low)/2;

            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
                ans= min(ans,arr[low]);
                low++;
                high--;
            }else if(arr[low]<=arr[mid]){
                if(ans>arr[low]){
                    ans = arr[low];
                }
                low=mid+1;
            }else{
                if(ans>arr[mid]){
                    ans=arr[mid];
                }
                high=mid-1;
            }
        }
        return ans;
    }
};
