#include<bits/stdc++.h>
using namespace std;

// Actual Process behind lower_bound STL function.
// int lowerBound(vector<int>& nums,int t){
//     int n = nums.size();
//     int low = 0,high = n-1;
//     int ans = n;
//     while(low <= high){
//         int mid = (low+high)/2;
//         if(nums[mid] >= t){
//             ans = mid;
//             high = mid -1;
//         }else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

int lowerBound(vector<int>& nums,int t){
    int x = lower_bound(nums.begin(),nums.end(),t) - (nums.begin());
    return x;
}

int main() {
    vector<int>arr = {1,3,4,7,9,13,15};
    int n = arr.size();
    int target;
    cin >> target;
    cout<<lowerBound(arr,target);
    return 0;
}