// Eg: [2 3 4 1]
// Ans: 3 equivalent to index of lower number.


#include <bits/stdc++.h>
int findKRotation(vector<int> &arr){
    // Write your code here. 
     int low=0,high=arr.size()-1;
        int ans=INT_MAX,ind=0;

        while(low<=high){
            int mid = low + (high-low)/2;

           if(arr[low]<=arr[mid]){
                if(ans>arr[low]){
                    ans = arr[low];
                    ind = low;
                }
                low=mid+1;
            }else{
                if(ans>arr[mid]){
                    ans=arr[mid];
                    ind = mid;
                }
                high=mid-1;
            }
        }
        return ind;   
}
