// Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
// A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing.

int LongestBitonicSequence(vector<int>arr)
{
    // code here
    int n = arr.size();
    vector<int>dp1(n,1),dp2(n,1);
    
    // Left to Right
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[j]<arr[i]){
                dp1[i] = max(dp1[i],1+dp1[j]);
            }
        }
    }
    
    // Righ to left
    for(int i=n-2;i>=0;i--){
        for(int j=n-1;j>i;j--){
            if(arr[i]>arr[j]){
                dp2[i] = max(dp2[i],1+dp2[j]);
            }
        }
    }
    
    int maxi=1;
    for(int i=0;i<n;i++){
        //cout<<dp1[i]<< "--->"<<dp2[i]<<endl;
        maxi = max(maxi, dp1[i] + dp2[i] -1);
    }
    
    return maxi;  
}
