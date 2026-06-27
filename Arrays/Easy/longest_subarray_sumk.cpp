#include<bits/stdc++.h>
using namespace std;
// Brute - Force Method. T.C -> O(n*n).  S.C -> O(1).

// int longest_SubArray(int arr[],int n,int k){
//     int maxLength = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < n; j++)
//         {
//             sum += arr[j];
//             if (sum == k )
//             {
//                 maxLength = max(maxLength , j-i+1);
//             }
//         }
//     }
//     return maxLength;
// }

// Better Method. T.C -> O(n*logn).  S.C -> O(n).
// if Array has positive numbers.

// int longest_SubArray(int arr[],int n,int k){
//     int sum = 0,maxLength = 0;
//     map<int,int>preSumMap;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//         if (sum == k)
//         {
//             maxLength = max(maxLength,i+1);
//         }
//         int rem = sum - k;
//         if (preSumMap.find(rem) != preSumMap.end())
//         {
//             int length = i - preSumMap[rem];
//             maxLength = max(length,maxLength);
//         }
//         preSumMap[sum] = i;
//     }
//     return maxLength;
// }

// Optimal Method. T.C -> O(2n).  S.C -> O(1).
// olny positive numbers. Using 2 pointer.

int longest_SubArray(int arr[], int n, int k)
{
    int left = 0, right = 0;
    int sum = 0;
    int maxLength = 0;
    while(right < n)
    {
        sum += arr[right];
        while(left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if(sum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
    }
    return maxLength;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cin>>k;
    cout<<longest_SubArray(arr,n,k);
    return 0;
}