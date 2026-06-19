#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N * (sum-max+1)), S.C -> O(1).

// int isPossible(vector<int>& nums, int paint, int k){
//     int count = 1,sum = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i] + sum <= paint){
//             sum += nums[i];
//         }else{
//             count++;
//             sum = nums[i];
//         }
//     }  
//     return count <= k;
// }

// int partition(vector<int>& nums, int k){
//     if(k > nums.size()) return -1;
//     int low = *max_element(nums.begin(),nums.end());
//     int high = accumulate(nums.begin(),nums.end(),0);
//     for (int i = low; i < high; i++)
//     {
//         if(isPossible(nums,i,k)){
//             return i;
//         }   
//     }
//     return -1;
// }

// Optimal. T.C -> O(N * log(sum-max+1)), S.C -> O(1).

int isPossible(vector<int>& nums, int paint, int k){
    int count = 1,sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] + sum <= paint){
            sum += nums[i];
        }else{
            count++;
            sum = nums[i];
        }
    }  
    return count <= k;
}

int partition(vector<int>& nums, int k){
    if(k > nums.size()) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(isPossible(nums,mid,k)){
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {10, 20, 30, 40};
    int k = 2;
    cout << partition(arr,k);
    return 0;
}