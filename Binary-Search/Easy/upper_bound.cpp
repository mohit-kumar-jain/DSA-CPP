#include<bits/stdc++.h>
using namespace std;
// Actual Process behind upper_bound STL function.
// int upperBound(vector<int>& nums,int target){
//     int n = nums.size();
//     int low = 0,high = n-1;
//     int ans = n;
//     while (low <= high)
//     {
//         int mid = (low + high)/2;
//         if(nums[mid] > target){
//             ans = mid;
//             high = mid - 1;
//         }else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

int upperBound(vector<int>& nums,int target){
    int x = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
    return x;
}

int main() {
    vector<int>arr = {1,3,4,7,9,13,15};
    int n = arr.size();
    int target;
    cin >> target;
    cout<<upperBound(arr,target);
    return 0;
}