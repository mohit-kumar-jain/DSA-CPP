#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n), S.C -> O(1).
// int findPeak(vector<int>& nums){
//     int n = nums.size();
//     int ans = -1;
//     if(n == 1) return 0;
//     if(nums[n-1] > nums[n-2]) return n-1;
//     for (int i = 0; i < n-1; i++)
//     {
//         if(nums[i] > nums[i+1]){
//             return i;
//         }
//     }
//     return ans;
// }

// Optimal. T.C -> O(logn), S.C -> O(1).
int findPeak(vector<int> &nums)
{
    int low = 0, high = nums.size() - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1])
        {
            low = mid + 1; // ascending slope peak is in right side
        }
        else
        {
            high = mid; // descending slop peak is at mid or left
        }
    }
    return low;
}

int main()
{
    vector<int> arr = {1,2,3,4,5,2,1};
    cout << findPeak(arr) << endl;
    return 0;
}