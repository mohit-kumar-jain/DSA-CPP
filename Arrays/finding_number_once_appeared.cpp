#include<bits/stdc++.h>
using namespace std;

// Brute - Force Method.T.C -> O(n*n).  S.C -> O(1).
// int ones_Appeared(int arr[],int n){
//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         int num = arr[i];
//         for (int j = 0; j < n-1; j++)
//         {
//             if(arr[j] == num) count ++;
//         }
//         if (count == 1)
//         {
//            return num;
//         }
//     }
//     return -1; 
// }

// Better Method.T.C -> O(3n).  S.C -> O(maxi+1).
// int ones_Appeared(int arr[],int n){
//     int maxi = 0;
//     for (int i = 0; i < n; i++)
//     {
//          maxi =  max(maxi,arr[i]);
//     }
//     int hashh[maxi+1] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         hashh[arr[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if(hashh[arr[i]] == 1){
//             return arr[i];
//         }
//     }
//     return -1;
// }

// Optimal Method.T.C -> O(n).  S.C -> O(1).
int ones_Appeared(int arr[],int n){
    int Xor = 0;
    for (int i = 0; i < n; i++)
    {
        Xor = Xor ^ arr[i];
    }
    return Xor;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<ones_Appeared(arr,n);
    return 0;
}