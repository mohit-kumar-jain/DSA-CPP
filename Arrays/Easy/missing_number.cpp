#include<bits/stdc++.h>
using namespace std;

// Brute-Force Method.Time Complexity -> O(n*n), Space Complexity -> O(1).
// Using loops.
// int find_Missing(int arr[],int n){
//     for (int i = 1; i <= n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < n-1; j++)
//         {
//             if (arr[j] == i)
//             {
//                 count = count + 1;
//             }
//         }
//         if (count == 0)
//         {
//             return i;
//         }
//     }
//     return -1;
// }

// Better Method. Time Complexity -> O(n+maxi), Space Complexity -> O(maxi).
// Using HASH MAP.
// int find_Missing(int arr[],int n){
//     int maxi = 0;
//     for (int i = 0; i < n; i++)
//     {
//         maxi = max(arr[i],maxi);
//     }
//     int hashh[maxi+1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         hashh[arr[i]]++;
//     }
//     for (int i = 1; i <= maxi; i++)
//     {
//         if (hashh[i] == 0)
//         {
//             return i;
//         }
//     }
//     return -1;  
// }

// Better Method. Time Complexity -> O(n), Space Complexity -> O(1).
// Using XOR.
int find_Missing(int arr[], int n)
{
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < n - 1; i++){
        xor2 ^= arr[i];
    }
    for(int i = 1; i <= n; i++){
        xor1 ^= i;
    }
    return xor1 ^ xor2;
}

int main() {
    int n;
    cin >> n;
    int arr[n-1];
    for (int i = 0; i < n-1; i++)
    {
        cin >> arr[i];
    }
    cout<<find_Missing(arr,n)<<endl;
    return 0;
}