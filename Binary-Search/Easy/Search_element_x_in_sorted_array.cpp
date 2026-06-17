#include<bits/stdc++.h>
using namespace std;
          
// Iterative Approach. T.C -> O(log n). S.C -> O(1).
int binarySearch(vector<int>& nums,int t){
    int n = nums.size();
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == t){
            return mid;
        }else if(nums[mid] > t){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

// Recursive Approach. T.C -> O(log n). S.C -> O(1).
// int binarySearch(vector<int>& nums,int low ,int high,int t){
//     while(low <= high){
//         int mid = (low+high)/2;
//         if(nums[mid] == t){
//             return mid;
//         }else if(nums[mid] > t){
//             return binarySearch(nums,0,mid-1,t);
//         }else{
//             return binarySearch(nums,mid+1,high,t);
//         }
//     }
//     return -1;
// }

int main() {
    vector<int> arr = {1,3,4,7,9,13,15};
    int n = arr.size();
    int target;
    cin >> target;
    cout<<binarySearch(arr,target);
    // cout<<binarySearch(arr,0,n-1,target);
    return 0;
}