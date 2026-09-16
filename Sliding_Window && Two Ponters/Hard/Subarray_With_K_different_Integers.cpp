#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(N*N*k), S.C -> O(k).
// int subarraysWithKDistinct(vector<int> &nums, int k)
// {
//     int n = nums.size();
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         unordered_map<int, int> freq;
//         for (int j = i; j < n; j++)
//         {
//             freq[nums[j]]++;
//             if (freq.size() == k)
//                 count++;
//             if (freq.size() > k)
//                 break;
//         }
//     }
//     return count;
// }

// Optimal. T.C -> O(N), S.C -> O(k).
int atMostK(vector<int> &nums, int K)
{
    unordered_map<int, int> freq;
    int left = 0, count = 0;
    for (int right = 0; right < nums.size(); right++)
    {
        if (freq[nums[right]] == 0)
        {
            K--;
        }
        freq[nums[right]]++;
        while (K < 0)
        {
            freq[nums[left]]--;
            if (freq[nums[left]] == 0)
            {
                K++;
            }
            left++;
        }
        count += (right - left + 1);
    }
    return count;
}

int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return atMostK(nums, k) - atMostK(nums, k - 1);
}

int main()
{
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << subarraysWithKDistinct(nums, k);
}
