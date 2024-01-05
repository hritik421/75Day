// We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:

// arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
// arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
// No integer is present in both arr1 and arr2.
// Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.

class Solution {
public:
    int minimizeSet(int d1, int d2, int uniqueCnt1, int uniqueCnt2) {
        long int low = uniqueCnt1 + uniqueCnt2;
        long int high = INT_MAX;
        long long int LCM = ((long long)d1*d2)/__gcd(d1,d2);
        while(low<=high){
            int mid = low + (high-low)/2;
            int notD1 = mid - mid/d1; // not divisble by d1
            int notD2 = mid - mid/d2; // not divisble by d2
            int notBoth = mid - mid/LCM; // not divisble by both
            if(notD1>=uniqueCnt1 && notD2>=uniqueCnt2 && notBoth>=(uniqueCnt1+uniqueCnt2)){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};
