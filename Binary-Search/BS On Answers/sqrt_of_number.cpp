#include<bits/stdc++.h>      
using namespace std;
             
// Brute. T.C -> O(sqrt(n)), S.C -> O(1).
// int floorSqrt(int nums){
//     if(nums == 0) return 0;
//     for(int i = 1; i < nums;i++){
//         long long sq = 1LL * i * i;
//         if(sq == nums)
//             return i;
//         if(sq > nums)
//             return i - 1;
//     }
//     return -1;
// }

// Optimal. T.C -> O(logn), S.C -> O(1).
int floorSqrt(int nums){
    if(nums == 0) return 0;
    int low = 1,high = nums, ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if((1LL * mid * mid) == nums){
            return mid;
        }else if((1LL * mid * mid) <= nums){
            ans = mid;
            low = (mid + 1);
        }else{
            high = mid - 1;
        }
    }
    return ans;
}


int main() {
    int num;
    cin >> num;
    cout << floorSqrt(num);
    return 0;
}