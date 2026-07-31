#include <bits/stdc++.h>
using namespace std;
// Brute. T.C -> O(2N), S.C -> O(1);
// int dominantIndex(vector<int> &nums) {
//     int maxi = nums[0];
//     int idx = 0;
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(maxi < nums[i]){
//             maxi = nums[i];
//             idx = i;
//         }
//     }
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if(i == idx) continue;
//         if(maxi < 2 * nums[i]){
//             return -1;
//         }
//     }
//     return idx;
// }

// Optimal. T.C -> O(N), S.C -> O(1).
int dominantIndex(vector<int> &nums)
{
    int idx = max_element(nums.begin(), nums.end()) - nums.begin();
    int maxi = nums[idx];

    for (int i = 0; i < nums.size(); i++)
    {
        if (i != idx && maxi < 2 * nums[i])
        {
            return -1;
        }
    }
    return idx;
}

int main()
{
    vector<int> nums = {1, 6, 3, 2, 0};
    cout << dominantIndex(nums) << endl;
    return 0;
}