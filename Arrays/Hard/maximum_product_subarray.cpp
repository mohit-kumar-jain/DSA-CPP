#include <bits/stdc++.h>
using namespace std;

// Brute. T.C -> O(n*n) ,S.C -> O(1).
// int productSubArray(vector<int>& nums){
//     int ans = 1;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i+1; j < n; j++)
//         {
//             if(nums[i] * nums[j] > ans){
//                 ans = nums[i] * nums[j];
//             }
//         }
//     }
//     return ans;
// }

//1.  Optimal. T.C -> O(n) ,S.C -> O(1).
int productSubArray(vector<int> &nums)
{
    int ans = INT_MIN;
    int n = nums.size();
    int pre = 1, suf = 1;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
        {
            pre = 1;
        }
        if (suf == 0)
        {
            suf = 1;
        }
        pre *= nums[i];
        suf *= nums[n - i - 1];
        ans = max(ans, max(pre, suf));
    }
    return ans;
}

// 2. Optimal. T.C -> O(n) ,S.C -> O(1).
int productSubArray(vector<int> &nums)
{
    // Initialize answer, max and min product as first element
    int res = nums[0];
    int maxProd = nums[0];
    int minProd = nums[0];

    // Traverse from second element
    for (int i = 1; i < nums.size(); i++)
    {
        // Store current number
        int curr = nums[i];

        // If current number is negative, swap max and min
        if (curr < 0)
            swap(maxProd, minProd);

        // Update max and min product ending at current index
        maxProd = max(curr, maxProd * curr);
        minProd = min(curr, minProd * curr);

        // Update global result
        res = max(res, maxProd);
    }

    // Return the result
    return res;
}

int main()
{
    vector<int> arr = {4, 6, 0, 10, 8, 1, -1};
    cout << productSubArray(arr) << endl;
    return 0;
}