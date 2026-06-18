#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n), S.C -> O(1).
// int noRotated(vector<int>& nums){
//     int n = nums.size();
//     for (int i = 0; i < n - 1; i++)
//     {
//         if(nums[i] > nums[i+1]){
//             return i+1;
//         }
//     }
//     return 0;
// }

// Better. T.C -> O(logn), S.C -> O(1).
int noRotated(vector<int>& nums)
{
    int low = 0;
    int high = nums.size() - 1;
    while(low < high)
    {
        int mid = low + (high - low) / 2;

        if(nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    vector<int> arr = { 3,4,5,6,0, 1, 2};
    cout << noRotated(arr) << endl;
    return 0;
}