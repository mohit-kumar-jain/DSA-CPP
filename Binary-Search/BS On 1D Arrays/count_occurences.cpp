#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n), S.C -> O(1).
// int countOccurences(vector<int>& nums,int t){
//     int n = nums.size(),cnt = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if(nums[i] == t){
//             cnt++;
//         }
//     }
//     return cnt;
// }

// optimal. T.C -> O(2*logn), S.C -> O(1).
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
int lowerBound(vector<int>& nums,int target){
    int l = lower_bound(nums.begin(),nums.end(),target) - nums.begin();
    return l;
}
int upperBound(vector<int>& nums,int target){
    int u = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
    return u;
}

int countOccurences(vector<int>& nums,int t){
    return upperBound(nums,t) - lowerBound(nums,t);
}

int main()
{
    vector<int> arr = {1, 3, 5, 5, 5, 7, 9, 11, 69};
    int target;
    cin >> target;
    cout << countOccurences(arr, target) << endl;
    return 0;
}