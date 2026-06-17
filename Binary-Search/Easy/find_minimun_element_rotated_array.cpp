#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n), S.C -> O(1).
// int findMin(vector<int>& nums){
//     int n = nums.size();
//     int minEle = INT_MAX;
//     for (int i = 0; i < n; i++)
//     {
//         minEle = min(minEle,nums[i]);
//     }
//     return minEle;
// }

// Better. T.C -> O(logn), S.C -> O(1).
int findMin(vector<int> &nums)
{
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return nums[low];
}

int main()
{
    vector<int> arr = {3, 4, 5, 0, 1, 2};
    cout << findMin(arr) << endl;
    return 0;
}