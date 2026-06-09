#include <bits/stdc++.h>
using namespace std;

// Brute -Force.T.C -> O(n*n) ,S.C -> O(1).
// int majorityElement(int arr[],int n){
//     for (int i = 0; i < n; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] == arr[i])
//             {
//                 count++;
//             }
//         }
//         if (count > (n/2))
//         {
//             return arr[i];
//         }  
//     }
//     return -1;
// }

// Better Method. T.C -> O(n*logn) ,S.C -> O(n).
// int majorityElement(int arr[],int n){
// map<int,int> mpp;
//     for (int i = 0; i < n; i++)
//     {
//         mpp[arr[i]] += 1;   
//     }
//     for(auto it:mpp){
//         if (it.second > (n/2))
//         {
//             return it.first;
//         }
//     }
//     return -1;  
// }

// Optimal Method. T.C -> O(n + n) ,S.C -> O(1).
int majorityElement(int arr[],int n){
    int count = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if(count == 0){
            ele = arr[i];
            count = 1;
        }
        else if(arr[i] == ele) count++;
        else count--;
    }
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == ele) count1++;
        if (count1 > (n/2)) 
        {
            return arr[i];
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout<<majorityElement(arr, n)<<endl;;
    return 0;
}