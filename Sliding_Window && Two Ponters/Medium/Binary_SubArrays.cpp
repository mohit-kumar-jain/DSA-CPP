#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N*N), S.C -> O(1).
// int numSubarraysWithSum(vector<int> &nums, int goal)
// {
//     int count = 0;
//     for (int start = 0; start < nums.size(); ++start)
//     {
//         int sum = 0;
//         for (int end = start; end < nums.size(); ++end)
//         {
//             sum += nums[end];
//             if (sum == goal)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Better. T.C -> O(N), S.C -> O(N).
// int numSubarraysWithSum(vector<int> &nums, int goal)
// {
//     unordered_map<int, int> prefixSumCount;
//     int count = 0, sum = 0;
//     prefixSumCount[0] = 1;
//     for (int num : nums)
//     {
//         sum += num;
//         if (prefixSumCount.find(sum - goal) != prefixSumCount.end())
//         {
//             count += prefixSumCount[sum - goal];
//         }
//         prefixSumCount[sum]++;
//     }
//     return count;
// }

// Optimal. T.C -> O(N) , S.C -> O(1).
int atMost(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int left = 0;
    int sum = 0;
    int count = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        sum += nums[right];
        while (sum > k)
        {
            sum -= nums[left];
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return atMost(nums, goal) - atMost(nums, goal - 1);
}

int main()
{
    vector<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    cout << numSubarraysWithSum(nums, goal) << endl;
    return 0;
}
