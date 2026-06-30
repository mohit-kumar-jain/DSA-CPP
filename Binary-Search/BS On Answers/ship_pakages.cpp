#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O((sum-max) * N), S.C -> O(1).

// bool mindays(vector<int> nums, int weight,int maxDays)
// {
//     int load = 0,days = 1;
//     for(int i = 0;i < nums.size();i++){
//         if(load + nums[i] > weight){
//             days += 1;
//             load = nums[i];
//         }else{
//             load += nums[i];
//         }
//     }
//     return days <= maxDays;
// }

// int leastWeight(vector<int> &nums, int days)
// {
//     int minCapacity = *max_element(nums.begin(), nums.end());
//     int maxCapacity = accumulate(nums.begin(), nums.end(), 0);
//     for(int i = minCapacity; i <= maxCapacity; i++)
//     {
//         if(mindays(nums, i, days))
//             return i;
//     }
//     return maxCapacity;
// }

// Optimal. T.C -> O(logn * N), S.C -> O(1).

bool minDays(vector<int> nums,int weight,int maxdays){
    int load = 0,days = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] + load <= weight){
            load += nums[i];
        }else{
            days += 1;
            load = nums[i];
        }
    }
    return days <= maxdays;
}

int leastWeight(vector<int> &nums, int days){
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    int ans = -1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(minDays(nums,mid,days)){
            ans = mid;
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {5, 4, 5, 2, 3, 4, 5, 6};
    int days = 5;
    cout << leastWeight(arr, days);
    return 0;
}