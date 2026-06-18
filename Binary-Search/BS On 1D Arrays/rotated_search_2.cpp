#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n), S.C -> O(1).
// int rotateSearch(vector<int>& nums,int t){
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         if(nums[i] == t){
//             return i;
//         }
//     }
//     return -1;
// }

// Optimal. T.C -> O(logn), S.C -> O(1).

bool rotateSearch(vector<int> &nums, int t)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] == t)
        {
            return true;
        }
        if(nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++,high--;
            continue;
        }
        else if (nums[low] <= nums[mid])
        { // Left half sorted
            if (nums[low] <= t && t < nums[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        { // Right half sorted
            if (nums[mid] < t && t <= nums[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {3,3,1,1,1,2,2,3,3};
    int target;
    cin >> target;
    cout << rotateSearch(arr, target) << endl;
    return 0;
}