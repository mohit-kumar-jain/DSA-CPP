#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N), S.C -> O(1).
// int findKthPositive(vector<int>& nums, int k)
// {
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i] <= k){
//             k++;
//         }else{
//             break;
//         }
//     }
//     return k;
// }

// Better. T.C -> O(logn), S.C -> O(1).
int findKthPositive(vector<int>& nums,int k){
    int low = 0,high = nums.size() - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        int missing = nums[mid] - (mid + 1);
        if(missing <  k){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return high + k +1;
}

int main()
{
    vector<int> arr = {5,6,7,8,10};
    int k = 5;
    cout << findKthPositive(arr, k);
    return 0;
}