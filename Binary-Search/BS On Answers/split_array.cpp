#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N) + O((sum-max+1)), S.C -> O(1).

// bool isPossible(vector<int>& nums, int numbers, int k){
//     int n = nums.size();
//     int sum = 0,cnt = 1;
//     for (int i = 0; i < n; i++)
//     {
//         if(nums[i] + sum <= numbers){
//             sum += nums[i];
//         }else{
//             cnt++;
//             sum = nums[i];
//         }
//     }
//     return cnt <= k;
// }

// int spilitArray(vector<int>& nums,int k){
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

// Optimal. T.C -> O(N) + O(log(sum-max+1)), S.C -> O(1).

bool isPossible(vector<int>& nums, int numbers, int k){
    int n = nums.size();
    int sum = 0,cnt = 1;
    for (int i = 0; i < n; i++)
    {
        if(nums[i] + sum <= numbers){
            sum += nums[i];
        }else{
            cnt++;
            sum = nums[i];
        }
    }
    return cnt <= k;
}

int spilitArray(vector<int>& nums,int k){
    if(k > nums.size()) return -1;
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    while(low <= high){
        int mid = low + (high - low) / 2;
        if (isPossible(nums,mid,k))
        {
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return low;
}
int main()
{
    vector<int> arr = {1,2,3,4,5};
    int k = 3;
    cout << spilitArray(arr,k);
    return 0;
}