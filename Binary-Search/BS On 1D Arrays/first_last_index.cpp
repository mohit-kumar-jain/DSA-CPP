#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n), S.C -> O(1).
// vector<int> firstLast(vector<int>& nums, int t)
// {
//     int first = -1, last = -1;
//     for(int i = 0; i < nums.size(); i++)
//     {
//         if(nums[i] == t)
//         {
//             if(first == -1)
//                 first = i;
//             last = i;
//         }
//     }
//     return {first, last};
// }

// Better. T.C -> O(logn), S.C -> O(1).
vector<int> firstLast(vector<int> &nums, int t)
{
    int first = -1;
    int n = nums.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == t)
        {
            first = mid;
            high = mid - 1;   
        }
        else if (nums[mid] > t)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    int last = -1;
    low = 0,high = n-1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] == t)
        {
            last = mid;
            low = mid + 1;   
        }
        else if (nums[mid] > t)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {first, last};
}

int main()
{
    vector<int> arr = {1, 3, 5, 5, 5, 7, 9, 11, 69};
    int target;
    cin >> target;
    vector<int> res = firstLast(arr, target);
    for (auto it : res)
    {
        cout << it << " ";
    }
    return 0;
}