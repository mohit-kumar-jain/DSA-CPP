#include <bits/stdc++.h>
using namespace std;

// Brute.T.C -> O(n*n) ,S.C -> O(1).
// int longestSubarraySum(int arr[],int n){
//     int maxxi = INT_MIN;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             maxxi = max(maxxi,sum);
//         }
//     }
//     return maxxi;
// }

// Optimal.T.C -> O(n) ,S.C -> O(1).
int longestSubarraySum(int arr[],int n){
    int maxxi = arr[0],sum =0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum > maxxi)
        {
            maxxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxxi;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<longestSubarraySum(arr, n)<<endl;
    return 0;
}