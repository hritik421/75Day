// Given a sorted array having N elements, find the indices of the first and last occurrences of an element X in the given array.

// Note: If the number X is not found in the array, return '-1' as an array.

vector<int> firstAndLast(vector<int> &arr, int n, int x) {
      // Code here
      int ind = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
      if(ind == n || arr[ind]!=x) return {-1};
      
      int uInd = upper_bound(arr.begin(),arr.end(),x) - arr.begin();
      
      return {ind, uInd-1};
  }

Note: Interviewer can ask to write Binary search code as well.
