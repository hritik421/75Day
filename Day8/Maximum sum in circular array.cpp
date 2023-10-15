#include <bits/stdc++.h> 
long long int DP(vector<int>& valueInHouse, int start, int end){
    long long int prev = valueInHouse[start];
    long long int prev2 = 0;
    
    for(int i=start+1;i<end;i++){
        long long int pick = valueInHouse[i] + prev2;
        long long int notPick = prev;
        prev2 = prev;
        prev = max(pick, notPick);
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    if(n==1) return valueInHouse[0];
    return max(DP(valueInHouse, 0,n-1),DP(valueInHouse,1,n));
}
